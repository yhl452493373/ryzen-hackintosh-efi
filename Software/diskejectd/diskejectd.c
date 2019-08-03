// Disk Eject Daemon
//
// (c) 2014 Andre Richter www.andre-richter.com
//
// A fork of: Mount Block Daemon
//
// (c) 2012 Adam Strzelecki nanoant.com
//
// Based on:
// http://superuser.com/questions/336455/mac-lion-fstab-is-deprecated-so-what-replaces-it-to-prevent-a-partition-from-m/336474#336474
//
// Compile with:
// cc diskejectd.c -g -o mountblockd -framework Foundation -framework DiskArbitration

#include <CoreFoundation/CoreFoundation.h>
#include <DiskArbitration/DiskArbitration.h>

CFStringRef *names = NULL;
int nameCount = 0;
bool run = true;
bool quiet = false;

void DiskEjectCallback(DADiskRef disk, DADissenterRef dissenter, void *context)
{
	if (dissenter) {
		if(!quiet) fprintf(stderr, "Ejected `%s'\n", DADiskGetBSDName(disk));
	} else {
		if(!quiet) fprintf(stderr, "Error ejecting: %s\n", DADiskGetBSDName(disk));
	}
}

void DiskClaimCallback(DADiskRef disk, DADissenterRef dissenter, void *context)
{
	if (!dissenter) {
		DADiskEject(disk, kDADiskEjectOptionDefault, DiskEjectCallback, NULL);        
	} else {
		if(!quiet) fprintf(stderr, "Error claiming disk %s!\n", DADiskGetBSDName(disk));
	}
}

void DiskAppearedCallback(DADiskRef disk, void *context)
{    
	CFDictionaryRef description = DADiskCopyDescription(disk);
	CFStringRef diskBSDName = description ? CFDictionaryGetValue(description, kDADiskDescriptionMediaBSDNameKey) : NULL;
 
	if (diskBSDName) {
		CFIndex diskBSDNameLength = CFStringGetMaximumSizeForEncoding(CFStringGetLength(diskBSDName), kCFStringEncodingUTF8);

		for (int i = 0; i < nameCount; i++) {
			if (CFEqual(diskBSDName, names[i]))
				DADiskClaim(disk, 0, 0, NULL, DiskClaimCallback, NULL);        
		}
	}
}

void signal_handler(int sig) {
	switch(sig) {
	case SIGHUP:
		if(!quiet) fprintf(stderr, "received SIGHUP signal, not supported\n");
		CFRunLoopStop(CFRunLoopGetCurrent());
		break;
	case SIGTERM:
		if(!quiet) fprintf(stderr, "received SIGTERM signal, terminating\n");
		run = false; CFRunLoopStop(CFRunLoopGetCurrent());
		break;
	case SIGINT:
		if(!quiet) fprintf(stderr, "received SIGINT signal, terminating\n");
		run = false; CFRunLoopStop(CFRunLoopGetCurrent());
		break;
	case SIGQUIT:
		if(!quiet) fprintf(stderr, "received SIGQUIT signal, terminating\n");
		run = false; CFRunLoopStop(CFRunLoopGetCurrent());
		break;
	default:
		fprintf(stderr, "uhandled signal (%d) %s\n", sig, strsignal(sig));
		break;
	}
}

int main(int argc, const char *argv[])
{
	int argi;
	bool useConsole;

	for (argi = 1; argi < argc && argv[argi][0] == '-'; argi++) {
		if (!strcmp(argv[argi], "-quiet")) {
			quiet = true;
		} else {
			fprintf(stderr, "unknown parameter `%s'\n", argv[argi]);
		}
	}

	signal(SIGHUP,  signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGINT,  signal_handler);
	signal(SIGQUIT, signal_handler);

	DAApprovalSessionRef session = DAApprovalSessionCreate(kCFAllocatorDefault);
	if (!session) {
		fprintf(stderr, "failed to create Disk Arbitration session\n");
	} else if (argc - argi <= 0) {
		fprintf(stderr, "usage: %s [-quiet] <name> ...\n", argv[0]);
	} else {        
		CFStringRef cfStringNames[argc - argi];        
		if(!quiet) fprintf(stderr, "blocking:\n");
		for(nameCount = 0; nameCount < argc - argi; nameCount++) {
			if(!quiet) fprintf(stderr, "(%d) `%s'\n", nameCount + 1, argv[nameCount + argi]);
			cfStringNames[nameCount] = CFStringCreateWithCStringNoCopy(NULL, 
										   argv[nameCount + argi],
										   kCFStringEncodingUTF8,
										   kCFAllocatorNull);
		}
		names = cfStringNames;

		DARegisterDiskAppearedCallback(session, NULL, DiskAppearedCallback, NULL);
		DAApprovalSessionScheduleWithRunLoop(session, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);

		while (run) {
			CFRunLoopRun();
		}

		DAApprovalSessionUnscheduleFromRunLoop(session, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
		DAUnregisterCallback(session, DiskAppearedCallback, NULL);
		CFRelease(session);
	}
	return 0;
}
