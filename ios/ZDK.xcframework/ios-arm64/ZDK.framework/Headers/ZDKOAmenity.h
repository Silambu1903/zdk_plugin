//
//  ZDKOAmenity.h
//  ZDK
//
//  Created by Diana Chabanova on 2019-06-26.
//  Copyright © 2019 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Amenity object.
 */
@protocol ZDKAmenity

/** @name Properties */

/**
 @brief Room title (Single room).
 */
@optional
@property(nullable, nonatomic, readonly) NSString *title;

/**
 @brief Uri for downloading icon.
 */
@property(nullable, nonatomic, readonly) NSString *iconUri;

@end

/**
 @brief Representation of the Zaplox Amenity object.
 */
@interface ZDKOAmenity : ZDKObject<ZDKAmenity>

@end

NS_ASSUME_NONNULL_END
