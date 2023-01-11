//
//  ZDKFindParameters.h
//  ZDK
//
//  Created by Nils Kjellin on 2018-12-10.
//  Copyright © 2018 Zaplox AB. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 * Holder class for parameters to be used for finding reservations.
 */
@interface ZDKFindParameters : NSObject

/** @name Methods */

/**
 @brief Initializes with the site id.

 @param siteId The site id.

 @return ZDKFindParameters
 */
- (instancetype )initWithSiteId:(NSString *)siteId;

/** @name Properties */

/**
 @brief Current set of parameters
 */
@property (strong, nonatomic) NSDictionary *params;

/** @name Parameters */

/**
 @brief Set phone number.

 @param phoneNumber Phone number
 */
- (void)setPhoneNumber:(NSString*)phoneNumber;

/**
 @brief Set email.

 @param email Email address
 */
- (void)setEmail:(NSString*)email;

/**
 @brief Set last name.

 @param lastName Last name
 */
- (void)setLastName:(NSString*)lastName;

/**
 @brief Set first name.

 @param firstName First name
 */
- (void)setFirstName:(NSString*)firstName;

/**
 @brief Set check in date.

 @param checkinDate Check in date
 */
- (void)setCheckinDate:(NSDate*)checkinDate;

/**
 @brief Set check out date.

 @param checkoutDate Check out date
 */
- (void)setCheckoutDate:(NSDate*)checkoutDate;

/**
 @brief Set PMS reference.

 @param pmsReference PMS reference
 */
- (void)setPMSReference:(NSString*)pmsReference;

/**
 @brief Set confirmation reference.

 @param confirmationReference Confirmation reference
 */
- (void)setConfirmationReference:(NSString*)confirmationReference;

/**
 @brief Set membership number.

 @param membershipNumber Membership number
 */
- (void)setMembershipNumber:(NSString*)membershipNumber;

/**
 @brief Set membership type.

 @param membershipType Membership type
 */
- (void)setMembershipType:(NSString*)membershipType;

/**
 @brief Set site id.

 @param siteId Site id
 */
- (void)setSiteId:(NSString*)siteId;

- (NSDictionary *)toDictionary;
@end

NS_ASSUME_NONNULL_END
