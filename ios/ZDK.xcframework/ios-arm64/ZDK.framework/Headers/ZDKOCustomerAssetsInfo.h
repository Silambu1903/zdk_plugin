//
//  ZDKOCustomerAssetInfo.h
//  ZDK
//
//  Created by Kevin Henriksson on 2021-10-30.
//  Copyright © 2021 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kCustomerAssetFindReservation;
extern NSString *const kCustomerAssetKeyTutorial;
extern NSString *const kCustomerAssetError;
extern NSString *const kCustomerAssetDiscover;

/**
 @brief Representation of the Zaplox Customer Assets Info object.
 */

@interface ZDKOCustomerAssetsInfo : ZDKObject

/** @name Properties */

/**
 @brief Find reservation header Image resources for customer.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *findReservation;

/**
 @brief Key tutorial header Image resources for customer.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *keyTutorial;

/**
 @brief Error header Image resources for customer.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *error;

/**
 @brief Discover header Image resources for customer.

 @return NSString
 */
@property (nullable, nonatomic, readonly) NSString *discover;

@end

NS_ASSUME_NONNULL_END
