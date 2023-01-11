//
//  ZDKOOffers.h
//  ZDK
//
//  Created by Diana Chabanova on 2019-09-12.
//  Copyright © 2019 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

@class ZDKOOffer;

NS_ASSUME_NONNULL_BEGIN
/**
 @brief Representation of the Zaplox object Offer.
 */
@interface ZDKOOffers : ZDKObject

@property (nonatomic, readonly) NSArray<ZDKOOffer*> *specialOffers;
@property (nonatomic, readonly) NSArray<ZDKOOffer*> *siteOffers;

@end

NS_ASSUME_NONNULL_END
