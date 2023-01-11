//
//  ZDKOFolioItem.h
//  ZDK
//
//  Created by David Aberg on 2017-08-02.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A Folio Item is representing a single row on a Folio.FolioWindow.
 */
@protocol ZDKFolioItem

/** @name Properties */

/**
 @brief Description of the purchased item.

 @note Example ```"Gym access"```
 */
- (nonnull NSString *)description;

/**
 @brief PMS internal product code of purchased items.

 @note Example ```"GYMACC01"```
 */
- (nonnull NSString *)productCode;

/**
 @brief Unit price.

 @note Example ```"100.00"```
 */
- (nonnull NSNumber *)unitPrice;

/**
 @brief Number of purchased items.

 @note Example ```"1"```
 */
- (nonnull NSNumber *)quantity;

@end

/**
 @brief Representation of the Zaplox Folio Item Object.
 */
@interface ZDKOFolioItem : ZDKObject <ZDKFolioItem>

@property (nonatomic, readonly) NSString *desc;
@property (nonatomic, readonly) NSNumber *origUnitPrice;
@property (nonatomic, readonly) NSString *origProductCode;
@property (nonatomic, readonly) NSDate *purchasedAt;
@property (nonatomic, readonly) NSNumber *origQuantity;

@end

NS_ASSUME_NONNULL_END
