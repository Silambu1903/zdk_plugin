//
//  ZDKDepositInfo.h
//  ZDK
//
//  Created by David Aberg on 2017-08-01.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"
#import "ZDKOFolio.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the Deposit Status connected to a Reservation in the Zaplox system. The Deposit indicates what amount that needs to be paid in deposit before checkin is possible.
 */
@protocol ZDKDepositInfo

/** @name Properties */

/**
 @brief The amount to pay before checkin in the lowest monetary unit.

 @note Example: 9.99 USD is noted as 999
 */
- (nullable NSNumber *)depositAmount;

/**
 @brief The Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 */
- (nullable NSString *)currencyCode;

/**
 @brief The amount paid in total, represented in the lowest monetary unit.

 @note Example: 9.99 USD is noted as 999
 */
- (nullable NSNumber *)paidTotal;

@end

/**
 @brief Representation of a Deposit Info in the Zaplox system.
 */
@interface ZDKODepositInfo : ZDKObject<ZDKDepositInfo>

@end

NS_ASSUME_NONNULL_END
