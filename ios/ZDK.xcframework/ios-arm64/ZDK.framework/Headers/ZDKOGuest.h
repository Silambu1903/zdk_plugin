//
//  Guest.h
//  Pods
//
//  Created by David Aberg on 12/08/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of a Guest registered on a Reservation.
 */
@protocol ZDKGuest

/** @name Properties */

/**
 @brief Concatenated name of guest.

 @note First name + Last name. Example: "Sven Svensson"
 */
- (nonnull NSString *)name;

/**
 @brief A dictionary with any of the guest propery key constants listed in this interface together with a value.
 */
- (nullable NSDictionary *)properties;

/**
 @brief Set guest properties.
 */
- (void)properties:(nullable NSDictionary *)properties;

@end

/**
 @brief Guest property key constants
 */
extern NSString * _Nonnull const GuestPropertyFirstName1;
extern NSString * _Nonnull const GuestPropertyFirstName2;
extern NSString * _Nonnull const GuestPropertyLastName1;
extern NSString * _Nonnull const GuestPropertyLastName2;
extern NSString * _Nonnull const GuestPropertyPhone1;
extern NSString * _Nonnull const GuestPropertyPhone2;
extern NSString * _Nonnull const GuestPropertyEmail;
extern NSString * _Nonnull const GuestPropertyAddress1;
extern NSString * _Nonnull const GuestPropertyAddress2;
extern NSString * _Nonnull const GuestPropertyAddress3;
extern NSString * _Nonnull const GuestPropertyZip;
extern NSString * _Nonnull const GuestPropertyCity;
extern NSString * _Nonnull const GuestPropertyState;
extern NSString * _Nonnull const GuestPropertyCountry;
extern NSString * _Nonnull const GuestPropertyNationality;
extern NSString * _Nonnull const GuestPropertyPassportNumber;

/**
 @brief Representation of a Guest registered on a Reservation.
 */
@interface ZDKOGuest : ZDKObject <ZDKGuest>

@property (nullable, nonatomic, readonly) NSString *primaryReference;

@end

NS_ASSUME_NONNULL_END
