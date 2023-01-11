//
//  ZDKOCommonInfo.h
//  Pods
//
//  Created by David Aberg on 29/09/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZDKCommonInfo

@end

/**
 @brief Representation of the Zaplox Common Info object.
 */
@interface ZDKOCommonInfo : ZDKObject<ZDKCommonInfo>

@property (nullable, nonatomic, readonly) NSString *desc;
@property (nullable, nonatomic, readonly) NSString *name;

@end

NS_ASSUME_NONNULL_END
