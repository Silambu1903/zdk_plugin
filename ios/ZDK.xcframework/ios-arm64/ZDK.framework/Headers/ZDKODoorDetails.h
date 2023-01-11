//
//  ZDKODoorDetails.h
//  ZDK
//
//  Created by Kevin Henriksson on 2022-07-04.
//  Copyright © 2022 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKODoorCommonInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZDKDoorDetails

/**
 @brief Common info.
 */
@property (nonatomic, readonly) ZDKODoorCommonInfo *commonInfo;

@end

@interface ZDKODoorDetails : ZDKObject <ZDKDoorDetails>

@end

NS_ASSUME_NONNULL_END
