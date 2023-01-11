//
//  KeyDetails.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import "ZDKObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZDKOKeyDetails : ZDKObject

@property (nonatomic, readonly) NSInteger keyType;
@property (nonatomic, readonly) NSString *thirdPartyContent;
@property (nonatomic, readonly) NSDate *dtend;
@property (nonatomic, readonly) NSDate *dtstart;

@end

NS_ASSUME_NONNULL_END
