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

@interface LHAppDelegate : NSObject <NSApplicationDelegate>

@property (nonatomic) IBOutlet NSWindow *welcomeWindow;
@property (nonatomic) IBOutlet NSTextField *usernameField;
@property (nonatomic) IBOutlet NSPopUpButton *recentDocumentsButton;

@property (nonatomic) BOOL busy;
@property (nonatomic) LFWebService* lfWebService;
@property (nonatomic) NSDate *launchDate;


-(IBAction)showWelcomeWindow:(id)sender;
-(IBAction)closeWelcomeWindow:(id)sender;

-(IBAction)openSurvey:(id)sender;
-(IBAction)openWebsite:(id)sender;

-(IBAction)lfAuthenticate:(id)sender;

-(BOOL)lfCheckUsername:(NSString*)username error:(NSError **)outError;

@end
