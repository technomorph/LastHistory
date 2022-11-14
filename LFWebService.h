//
//  LFWebService.h
//  LastHistory
//
//  Created by Frederik Seiffert on 28.11.08.
//  Copyright 2008 Frederik Seiffert. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

extern NSString *LFWebServiceErrorDomain;

@interface LFWebService : NSObject {
	NSString *_apiKey;
	NSString *_secret;
	
	NSString *_userName;
	NSString *_sessionKey;
	
	NSString *_token; // used during authorization
}

@property (readonly, copy) NSString *apiKey;
@property (readonly, copy) NSString *secret;

@property (readonly, copy) NSString *userName;
@property (readonly, copy) NSString *sessionKey;

@property (readonly) BOOL isAuthenticated;


-(id)initWithApiKey:(NSString*)apiKey secret:(NSString*)secret;
-(id)initWithApiKey:(NSString*)apiKey
			  secret:(NSString*)secret
			userName:(NSString*)userName
		  sessionKey:(NSString*)sessionKey;



-(NSString*)authenticateGetToken;
-(NSURL*)authenticateGetAuthorizationURL;
-(BOOL)authenticateFinish;

-(NSXMLDocument*)callMethod:(NSString*)methodName withParameters:(NSDictionary*)params error:(NSError **)outError;
-(NSXMLDocument*)callAuthenticatedMethod:(NSString*)methodName withParameters:(NSDictionary*)params error:(NSError **)outError;

@end
