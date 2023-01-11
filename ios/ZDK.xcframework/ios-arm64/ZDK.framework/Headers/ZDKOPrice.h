//
//  ZDKOPrice.h
//  Pods
//
//  Created by David Aberg on 30/09/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Zaplox Price object.
 */
@interface ZDKOPrice : ZDKObject

/** @name Properties */

@property (nonatomic, readonly) NSString *isoCurrencyCode;
@property (nonatomic, readonly) NSNumber *price;
@property (nonatomic, readonly) NSNumber *tax;

@end

NS_ASSUME_NONNULL_END
