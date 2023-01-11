//
//  ZaploxJSONModel.h
//  Pods
//
//  Created by David Aberg on 13/08/15.
//
//

#import <Foundation/Foundation.h>
#import "ZDKConstantsAndEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZDKObject : NSObject

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

+ (NSArray *)arrayOfDataObjectsFromDictionariesInArray:(NSArray *)array;
+ (instancetype)dataObjectWithDictionary:(NSDictionary *)dictionary;
+ (NSString *)getVarAsRoute:(NSString *)param;

@end

@interface NSDictionary (TypedChecked)
/**
 *  Returns nil if objectForKey: isn't of the return type aClass, otherwise it's the same as objectForKey:
 *
 *  @param aKey the key to look up.
 *  @param aClass the class to verify.
 *
 *  @return The result of objectForKey, except for if that's of a different type than aClass then it returns nil.
 */
- (nullable id)objectForKey:(id)aKey ofClass:(Class)aClass;

- (nullable NSArray *)arrayForKey:(nonnull id)aKey;
- (nullable NSData *)dataForKey:(nonnull id)aKey;
- (nullable NSDictionary *)dictionaryForKey:(nonnull id)aKey;
- (nullable NSNumber *)numberForKey:(nonnull id)aKey;
- (nullable NSString *)stringForKey:(nonnull id)aKey;
- (nullable NSDate *)dateForKey:(nonnull id)aKey;

@end

NS_ASSUME_NONNULL_END
