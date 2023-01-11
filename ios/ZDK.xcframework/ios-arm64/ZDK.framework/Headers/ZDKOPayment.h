//
//  ZDKOPayment.h
//  ZDK
//
//  Created by David Aberg on 2017-08-01.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of a Payment in the Zaplox system.
 */
@protocol ZDKPayment

/** @name Properties */

/**
 @brief The unique Zaplox Identifier for the Payment.
 */
- (nonnull NSString *)zuid;

/**
 @brief Verification redirect URL for the payment.
 */
- (nonnull NSString *)verificationUrl;

/**
 @brief currency Currency code as defined by ISO4217 (i.e. EUR, SEK, USD)
 */
- (nonnull NSString *)currency;

/**
 @brief The total amount for the registered payment in the lowest monetary unit.

 @note Example: 9.99 USD is noted as 999
 */
- (nonnull NSNumber *)totalAmount;

@end

/**
 @brief Representation of a Payment in the Zaplox system.
 */
@interface ZDKOPayment : ZDKObject <ZDKPayment>

@property (nonatomic, readonly) NSString *paymentZuid;
@property (nonatomic, readonly) NSString *reservationZuid;
@property (nonatomic, readonly) NSString *siteZuid;
@property (nonatomic, readonly) NSString *paymentState;
@property (nonatomic, readonly) BOOL deposit;
@property (nonatomic, readonly) NSNumber *total;
@property (nonatomic, readonly) NSString *redirectUrl;
@property (nullable, nonatomic, readonly) NSString *isoCurrencyCode;
@property (nonatomic, readonly) NSDate *createdAt;
@property (nonatomic, readonly) NSDate *updatedAt;

@end

NS_ASSUME_NONNULL_END
