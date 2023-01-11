//
//  ZDKOContactInfo.h
//  Pods
//
//  Created by David Aberg on 29/09/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Contact Info object.
 */
@protocol ZDKContactInfo

/** @name Properties */

/**
 @brief Email address to the hotel.
 */
@optional
@property (nullable, nonatomic, readonly) NSString *email;

/**
 @brief Contact person at the hotel.
 */
@property (nullable, nonatomic, readonly) NSString *person;

/**
 @brief Phone number to the hotel.
 */
@property (nullable, nonatomic, readonly) NSString *phone;

/**
 @brief Uri to the hotel.
 */
@property (nullable, nonatomic, readonly) NSString *uri;

@end

/**
 @brief Representation of the Zaplox Contact Info object.
 */
@interface ZDKOContactInfo : ZDKObject<ZDKContactInfo>

@end

NS_ASSUME_NONNULL_END
