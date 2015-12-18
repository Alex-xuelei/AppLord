//
//  ALModule.h
//  AppLord
//
//  Created by 念纪 on 15/11/9.
//  Copyright © 2015年 cnbluebox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppLord/ALContext.h>

#undef AL_EXPORT_MODULE
#define AL_EXPORT_MODULE \
+ (void)load { [[ALContext sharedContext] registModule:[self class]]; }

@protocol ALModule <NSObject>

/**
 *  module did create
 */
- (void)moduleDidInit:(ALContext *_Nonnull)context;

@optional

/**
 *  receive a event
 */
- (void)moduleDidReceiveEvent:(ALEvent *_Nonnull)event;

/**
 *  config when load this module, init when it's first used
 */
+ (BOOL)loadWhenNeeded;

/**
 *  config when load this module, init when main thread is idle
 */
+ (BOOL)loadAfterLaunch;

@end

