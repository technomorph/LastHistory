	//
	//  LHHistoryRetrievalOperation.h
	//  LastHistory
	//
	//  Created by Frederik Seiffert on 13.12.09.
	//  Copyright 2009 Frederik Seiffert. All rights reserved.
	//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import "LHOperation.h"

@class LHUser;
@class LHHistoryEntry;

@interface LHHistoryRetrievalOperation : LHOperation {
	NSString *_username;
	LHUser *_user;
	LHHistoryEntry *_firstHistoryEntry;
	LHHistoryEntry *_lastHistoryEntry;
	
	NSEntityDescription	*_historyEntryEntity;
	NSEntityDescription	*_trackEntity;
	NSEntityDescription	*_albumEntity;
	NSEntityDescription	*_artistEntity;
}

@property (readonly) NSString *username;

-(id)initWithDocument:(LHDocument*)document andUsername:(NSString*)username;


@end
