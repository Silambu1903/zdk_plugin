//
//  ZDKOFolio.h
//  ZDK
//
//  Created by David Aberg on 2017-08-02.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKOFolioWindow.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of a Folio connected to a Reservation in the Zaplox system. A Folio includes a list of all costs and payments that is associated to a reservation.
*/
@protocol ZDKFolio

/** @name Properties */

/**
 @brief The amount paid in total, represented in the lowest monetary unit.

 @note Example: 9.99 USD is noted as 999
 */
- (nonnull NSString *)paidTotal;

/**
 @brief The Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 */
- (nonnull NSString *)currencyCode;

/**
 @brief The list of folio windows connected to this folio.
 */
- (nullable NSArray<ZDKOFolioWindow *> *)windows;

@end

/**
 @brief Representation of the Zaplox Folio Object.
*/
@interface ZDKOFolio : ZDKObject <ZDKFolio>

@property (nullable, nonatomic, readonly) NSString *isoCurrencyCode;
@property (nonatomic, readonly) NSNumber *origPaidTotal;
@property (nullable, nonatomic, readonly) NSArray /*ZDKOFolioWindow*/ *folioWindows;

@end

NS_ASSUME_NONNULL_END
