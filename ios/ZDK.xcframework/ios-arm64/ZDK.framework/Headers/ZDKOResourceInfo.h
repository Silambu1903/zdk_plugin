//
//  ResourceInfo.h
//  Pods
//
//  Created by David Aberg on 29/09/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Resource info object.
 */
@protocol ZDKResourceInfoProtocol

/** @name Properties */

/**
 @brief Site header image.
 */
@optional
@property (nullable, nonatomic, readonly) NSString *headerImageUri;

/**
 @brief Site thumbnail image.
 */
@property (nullable, nonatomic, readonly) NSString *thumbnailImageUri;

/**
 @brief Site icon image.
 */
@property (nullable, nonatomic, readonly) NSString *iconImageUri;

@end

/**
 @brief Representation of the Zaplox Resource info object.
 */
@interface ZDKOResourceInfo : ZDKObject <ZDKResourceInfoProtocol>

@end

NS_ASSUME_NONNULL_END
