//
//  ZDKODoorCommonInfo.h
//  ZDK
//
//  Created by Kevin Henriksson on 2022-07-04.
//  Copyright © 2022 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZDKDoorCommonInfo

/**
 @brief Door status.
 */
@property (nonatomic, readonly) NSInteger status;

@end

@interface ZDKODoorCommonInfo : ZDKObject <ZDKDoorCommonInfo>

@end

NS_ASSUME_NONNULL_END
