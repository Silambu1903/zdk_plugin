//
//  ZDKORoomInfo.h
//  ZDK
//
//  Created by Diana Chabanova on 2019-06-26.
//  Copyright © 2019 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKOAmenity.h"
#import "ZDKOOffer.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Room info object.
 */
@protocol ZDKRoomInfo

/** @name Properties */

/**
 @brief Room title (tex Single room).
 */
@optional
@property (nullable, nonatomic, readonly) NSString *title;

/**
 @brief Room subTitle (tex 2 beds).
 */
@property (nullable, nonatomic, readonly) NSString *subTitle;

/**
 @brief Room description.
 */
@property (nullable, nonatomic, readonly) NSString *text;

/**
 @brief Room header image uri.
 */
@property (nullable, nonatomic, readonly) NSString *headerImageUri;

/**
 @brief Image resources for room.

 @return ZDKResourceInfoProtocol
 */
@property (nullable, nonatomic, readonly) ZDKOResourceInfo *appResourceInfo;

/**
 @brief Amenities and services.

 @return A list of ZDKAmenity.
 */
@property (nonatomic, readonly) NSArray<ZDKOAmenity *> *amenities;

@end

/**
 @brief Representation of the Zaplox Room info object.
 */
@interface ZDKORoomInfo : ZDKObject <ZDKRoomInfo>

- (instancetype)initWithOffer:(ZDKOOffer *)offer;

@end

NS_ASSUME_NONNULL_END
