//
//  ZDKOAddressInfo.h
//  Pods
//
//  Created by David Aberg on 29/09/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Geolocation object.
 */
@protocol ZDKGeo

/**
 @brief Geolocation latitude.
 */
@property (nonatomic, readonly) double latitude;

/**
 @brief Geolocation longitude.
 */
@property (nonatomic, readonly) double longitude;

@end

/**
 @brief Representation of the Zaplox Geolocation object.
 */
@interface ZDKOGeo : ZDKObject<ZDKGeo>
@end


/**
 Representation of the Zaplox Address Info object.
 */
@protocol ZDKAddressInfo

/** @name Properties */

/**
 @brief Address line 1.
 */
@optional
@property (nullable, nonatomic, readonly) NSString *address1;

/**
 @brief Address line 2.
 */
@property (nullable, nonatomic, readonly) NSString *address2;

/**
 @brief City.
 */
@property (nullable, nonatomic, readonly) NSString *city;

/**
 @brief Country.
 */
@property (nullable, nonatomic, readonly) NSString *country;

/**
 @brief Geo location as string.
 */
@property (nullable, nonatomic, readonly) NSString *geo;

/**
 @brief Geo location.
 */
@property (nullable, nonatomic, readonly) ZDKOGeo *geoLocation;

/**
 @brief Region.
 */
@property (nullable, nonatomic, readonly) NSString *region;

/**
 @brief Zipcode.
 */
@property (nullable, nonatomic, readonly) NSString *zipcode;

@end

/**
 @brief Representation of the Zaplox Address Info object.
 */
@interface ZDKOAddressInfo : ZDKObject <ZDKAddressInfo>
@end

NS_ASSUME_NONNULL_END
