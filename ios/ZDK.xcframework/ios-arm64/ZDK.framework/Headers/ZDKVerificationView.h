//
//  ZDKVerificationView.h
//  ZDK
//
//  Created by Diana Chabanova on 2019-08-27.
//  Copyright © 2019 Zaplox AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "ZDKObject.h"

@class ZDKVerificationView, ZDKError, ZDKOReservation, ZDKOPaymentWindow;

NS_ASSUME_NONNULL_BEGIN

@protocol ZDKVerificationViewDelegate <NSObject>

@optional
/**
 @brief Invoked when a verification view is loaded.
 @param verificationView The verification view invoking the delegate method.
 */
- (void)didFinishLoading:(ZDKVerificationView *)verificationView;

/**
 @brief Invoked when a verification view succesfully registeres payment.
 @param verificationView The verification view invoking the delegate method.
 @param zuid The zuid of the payment object.
 */
- (void)verificationView:(ZDKVerificationView *)verificationView didRegisterPayment:(NSString *)zuid;

/**
 @brief Invoked when a verification view fails to register a payment.
 @param verificationView The verification view invoking the delegate method.
 @param error The error that occurred.
 */
- (void)verificationView:(ZDKVerificationView *)verificationView didFailWithError:(ZDKError *)error;

@end

@interface ZDKVerificationView : WKWebView<WKUIDelegate, WKNavigationDelegate>

/** The verification view's delegate. */
@property (nullable, nonatomic, weak) id <ZDKVerificationViewDelegate> delegate;

/**
 @brief Starts payment verification process for the reservation.
 @param reservation The reservation to be paid.
 @param window The payment window.
 @param currency Currency.
 */
- (void)startVerification:(ZDKOReservation *)reservation window:(ZDKOPaymentWindow *)window currency:(NSString *)currency;

/**
 @brief Starts payment verification process for the reservation.
 @param paymentType ZDKPaymentType - Pay, Authorize, Capture, Tokenize
 @param reservation The reservation to be paid.
 @param window The payment window.
 @param currency Currency.
 */
- (void)startVerification:(ZDKOReservation *)reservation withType:(ZDKPaymentType)paymentType window:(ZDKOPaymentWindow *)window currency:(NSString *)currency;

/**
 @brief Stops ongoing loading of payment verification view.
 */
- (void)stopLoadingView;

@end

NS_ASSUME_NONNULL_END
