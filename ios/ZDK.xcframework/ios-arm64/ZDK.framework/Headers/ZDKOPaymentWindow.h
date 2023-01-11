//
//  ZDKOPaymentWindow.h
//  ZDK
//
//  Created by David Aberg on 2017-08-01.
//  Copyright © 2017 Zaplox AB. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Describes the specifics for a Payment, and which amount to be paid for which window in the PMS.
 */
@protocol ZDKPaymentWindow

/** @name Methods */

/**
 @brief Designated initializer for ZDKOPaymentWindow.
 
 @param windowNumber Describes the specifics for a Payment, and which amount to be paid for which window in the PMS.
 @param sum Amount in the lowest monetary unit, example: 9.99 USD is noted as 999
*/
- (nonnull instancetype)initWithWindowNumber:(NSNumber * _Nonnull)windowNumber sum:(NSNumber *_Nonnull)sum;

@end

/**
 @brief Representation of a PaymentWindow in the Zaplox system.
 */
@interface ZDKOPaymentWindow : NSObject

/** @name Properties */

/**
 @brief Payment window number.
*/
@property (nonatomic) NSNumber *windowNumber;

/**
 @brief Total sum to be payed.
*/
@property (nonatomic) NSNumber *sum;

- (nonnull instancetype )initWithWindowNumber:(NSNumber * _Nonnull)windowNumber sum:(NSNumber *_Nonnull)sum;
- (NSDictionary * _Nonnull)toDictionary;

@end

NS_ASSUME_NONNULL_END
