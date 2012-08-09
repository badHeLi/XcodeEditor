////////////////////////////////////////////////////////////////////////////////
//
//  EXPANZ
//  Copyright 2008-2011 EXPANZ
//  All Rights Reserved.
//
//  NOTICE: Expanz permits you to use, modify, and distribute this file
//  in accordance with the terms of the license agreement accompanying it.
//
////////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>

@class XCProject;
@class XCSourceFile;

/**
* Represents a target in an xcode project.
*/
@interface XCTarget : NSObject {

    __weak XCProject* _project;
    NSString* _key;
    NSString* _name;
    NSString* _productName;
    NSString* _productReference;

@private
    NSMutableArray* _members;
    NSMutableArray* _resources;
}

@property(nonatomic, strong, readonly) NSString* key;
@property(nonatomic, strong, readonly) NSString* name;
@property(nonatomic, strong, readonly) NSString* productName;
@property(nonatomic, strong, readonly) NSString* productReference;

+ (XCTarget*) targetWithProject:(XCProject*)project key:(NSString*)key name:(NSString*)name productName:(NSString*)productName productReference:(NSString*)productReference;

- (id) initWithProject:(XCProject*)project key:(NSString*)key name:(NSString*)name productName:(NSString*)productName productReference:(NSString*)productReference;

- (NSArray*) resources;
- (NSArray*) members;

- (void) addMember:(XCSourceFile*)member;

- (void) removeMemberWithKey:(NSString*)key;

- (void) removeMembersWithKeys:(NSArray*)keys;

- (void) addDependency:(NSString*)key;

@end

