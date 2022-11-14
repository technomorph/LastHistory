	//
	//  LHDocument.h
	//  LastHistory
	//
	//  Created by Frederik Seiffert on 04.10.09.
	//  Copyright Frederik Seiffert 2009 . All rights reserved.
	//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import "LHEvent.h"

extern NSString *LHDocumentWillOpenNotification;
extern NSString *LHDocumentDidOpenNotification;
extern NSString *LHDocumentDidCloseNotification;

@class LHHistoryView;
@class LHTrack;
@class LHHistoryEntry;
@class LHOperation;

@interface LHDocument : NSPersistentDocument <NSSoundDelegate>
{
	NSArray *_cachedHistoryEntries;
	NSUInteger _hiddenHistoryEntriesCount;
	NSUInteger _hiddenTracksCount;
	
	LHHistoryEntry *_currentHistoryEntry;
	id<LHEvent> _currentEvent;
	
	NSSound *_currentSound;
	BOOL _currentSoundIsPaused;
	
	NSOperationQueue *_queue;
}

@property (readonly) IBOutlet LHHistoryView *historyView;
@property (readonly) IBOutlet NSTokenField* searchField;
@property (readonly) IBOutlet NSWindow* usernameSheet;
@property (readonly) IBOutlet NSTextField* usernameField;
@property (readonly) IBOutlet NSWindow* playlistNameSheet;
@property (readonly) IBOutlet NSTextField* playlistNameField;


@property (assign) int operationMode;
@property (assign) BOOL chartsMode;
@property (retain) NSArray *playlist;

@property (retain) LHHistoryEntry *currentHistoryEntry;
@property (retain) id<LHEvent> currentEvent;
@property (retain) NSSound *currentSound;

@property (readonly) NSString *infoString;

@property (readonly) NSArray *tracks;
@property (readonly) NSUInteger tracksCount;

@property (readonly) NSArray *historyEntries;
@property (readonly) NSUInteger historyEntriesCount;

@property (readonly) LHHistoryEntry *firstHistoryEntry;
@property (readonly) LHHistoryEntry *lastHistoryEntry;

@property (retain) LHOperation *currentOperation;


-(void)setUsername:(NSString*)username;


-(void)updateOperation:(LHOperation*)op;
-(void)mergeChanges:(NSNotification*)notification;


-(NSArray*)objectsForEntity:(NSString*)entityName
			  withPredicate:(NSPredicate*)predicate
				 fetchLimit:(NSUInteger)fetchLimit
				  ascending:(BOOL)ascending
				  inContext:(NSManagedObjectContext*)context;
-(NSArray*)objectsForEntity:(NSString*)entityName;

-(NSUInteger)countForEntity:(NSString*)entityName
			  withPredicate:(NSPredicate*)predicate
				  inContext:(NSManagedObjectContext*)context;
-(NSUInteger)countForEntity:(NSString*)entityName;


	// Actions

-(IBAction)updateFilter:(id)sender;

-(void)performFindPanelAction:(id)sender;
-(IBAction)toggleFullScreenMode:(id)sender;

-(IBAction)showTrackIniTunes:(id)sender;
-(IBAction)createPlaylistIniTunes:(id)sender;
-(IBAction)closePlaylistNameSheet:(id)sender;

-(IBAction)stop:(id)sender;
-(IBAction)pause:(id)sender;

-(IBAction)skipBackwards:(id)sender;
-(IBAction)skipForward:(id)sender;

-(BOOL)playHistoryEntry:(LHHistoryEntry*)historyEntry;
-(BOOL)playHistoryEntriesForEvent:(id <LHEvent>)event;
-(NSUInteger)numberOfHistoryEntriesForEvent:(id <LHEvent>)event;

	// History Loading

-(IBAction)loadHistory:(id)sender;
-(IBAction)closeUsernameSheet:(id)sender;

	// Last.fm Tag Loading

-(IBAction)retrieveTags:(id)sender;
-(IBAction)showTopTags:(id)sender;

@end
