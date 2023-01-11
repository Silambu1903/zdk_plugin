//
//  ZDKOPaymentInfo.h
//  Pods
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
@brief Representation of the Zaplox Payment Info object.
*/
@protocol ZDKPaymentInfo

@end

/**
 @brief Representation of the Zaplox Payment Info object.
 */
@interface ZDKOPaymentInfo : ZDKObject<ZDKPaymentInfo>

/** @name Properties */

/**
 @brief Boolean indicating that tokenized payment is used.
*/
@property (nonatomic, readonly) BOOL isTokenized;

/**
 @brief Window number for deposit payments.
*/
@property (nonatomic, readonly) NSInteger depositWindow;


@end

NS_ASSUME_NONNULL_END
