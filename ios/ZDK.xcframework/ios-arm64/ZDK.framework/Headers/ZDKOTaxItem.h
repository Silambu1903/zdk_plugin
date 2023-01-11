//
//  ZDKOTaxItem.h
//  ZDK
//
//  Created by David Aberg on 2017-08-02.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A Tax Item is representing a single tax item on a Folio.FolioWindow.
 */
@protocol ZDKTaxItem

/** @name Properties */

/**
 @brief The name of the tax item.
 */
- (nonnull NSString *)name;

/**
 @brief The amount in the lowest monetary unit.

 @note Example: 9.99 USD is noted as 999
 */
- (nonnull NSNumber *)amount;

/**
 @brief The percentage.
 */
- (nonnull NSNumber *)percentage;


@end

/**
 @brief Representation of the Zaplox TaxItem Object.
 */
@interface ZDKOTaxItem : ZDKObject <ZDKTaxItem>

@property (nonatomic, readonly) NSString *origName;
@property (nonatomic, readonly) NSNumber *origAmount;
@property (nonatomic, readonly) NSNumber *origPercentage;

@end

NS_ASSUME_NONNULL_END
