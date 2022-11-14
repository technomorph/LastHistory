	//
	//  LHAppDelegate.h
	//  LastHistory
	//
	//  Created by Frederik Seiffert on 29.10.09.
	//  Copyright 2009 Frederik Seiffert. All rights reserved.
	//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

@class LFWebService;

@interface LHAppDelegate : NSObject <NSApplicationDelegate, NSUserNotificationCenterDelegate>

@property (readonly) IBOutlet NSWindow* welcomeWindow;
@property (readonly) IBOutlet NSTextField* usernameField;
@property (readonly) IBOutlet NSPopUpButton* recentDocumentsButton;

@property (readonly) LFWebService* lfWebServices;

@property BOOL busy;
@property (copy) NSDate* launchDate;


-(IBAction)showWelcomeWindow:(id)sender;
-(IBAction)closeWelcomeWindow:(id)sender;

//-(IBAction)openSurvey:(id)sender;
//-(IBAction)openWebsite:(id)sender;

-(IBAction)lfAuthenticate:(id)sender;

-(BOOL)lfCheckUsername:(NSString*)username error:(NSError **)outError;

@end
