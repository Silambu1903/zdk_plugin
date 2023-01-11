//
//  OfferFeature.h
//  Pods
//
//  Created by David Aberg on 03/09/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Representation of the Zaplox Offer Feature object.
 */
@interface ZDKOOfferFeature : ZDKObject
/** @name Properties */

@property (nullable, nonatomic, readonly) NSString *desc;
@property (nullable, nonatomic, readonly) NSString *iconUri;
@property (nullable, nonatomic, readonly) NSString *title;
@property (nullable, nonatomic, readonly) NSString *zuid;

@end

NS_ASSUME_NONNULL_END
