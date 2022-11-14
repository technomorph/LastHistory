	//
	//  LHOperation.h
	//  LastHistory
	//
	//  Created by Frederik Seiffert on 20.11.09.
	//  Copyright 2009 Frederik Seiffert. All rights reserved.
	//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

@class LHDocument;

@interface LHOperation : NSOperation {
	NSManagedObjectContext *_context;
	LHDocument* _document;
	NSString* _progressMessage;
	float _progress;
	BOOL _progressIndeterminate;
}

@property (readonly) LHDocument* document;
@property (readonly) NSManagedObjectContext *context;

@property (retain) NSString *progressMessage;
@property (assign) float progress;
@property (assign) BOOL progressIndeterminate;

-(id)initWithDocument:(LHDocument*)document;

-(BOOL)saveContext;

@end
