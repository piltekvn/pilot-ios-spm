//
//  OTT.h
//  Client_ReactNative
//
//  Created by NguyenVanSao on 2/19/20.
//  Copyright © 2020 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OTT : NSObject
+(OTT *)getInstance;
-(void)initialize:(NSString *)clientKey;
-(NSString *)generate:(NSString *)url configKey:(NSString *)configKey;
-(void)start:(NSString *)url;
-(void)stop;
@end

NS_ASSUME_NONNULL_END
