//
//  TransactionId.h
//  Zaplox
//
//  Copyright (c) 2015 Zaplox AB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDKObject.h"

@interface ZDKTransaction : NSObject

typedef NS_ENUM(NSInteger, TransactionType) {
    CreateAccount               = 400,
    ReadAccount                 = 401,
    UpdateAccount               = 402,
    ValidateIdentity            = 404,
    ReadIdentity                = 406,
    ReadDevice                  = 410,
    ReadDoor                  	= 313,
    UpdateDevice                = 411,
    LogoutDevice                = 412,
    LoginAccount                = 413,
    ReadOffer                   = 1001,
    ReadSite                    = 309,
    ReadReservation             = 900,
    UpdateReservation           = 901,
    UpdateThirdPartyKeyStores   = 420,
    ShareKey                    = 504,
    OnlineUnlock                = 520,
    SyncKeys                    = 540,
    SyncedKeys                  = 541,
    ClaimKey                    = 530,
    LogThirdPartyUnlock         = 800
};

@property (strong, nonatomic) NSDictionary *dictionaryRepresentation;
@property (strong, nonatomic) NSString *transactionId;
@property (strong, nonatomic) NSString *url;
@property (nonatomic) TransactionType type;
@property (nonatomic) NSInteger beginAt;
@property (strong, nonatomic) NSString *accountZuid;
@property (strong, nonatomic) NSString *objectZuid;

@property (nonatomic) NSInteger numberOfGetStatusCalls;

- (void)getStatusWithCompletion:(ZDKCompletionBlock)completeBlock;

// Generates a unique hex key to be used for identifying transactions
- (id)initWithType:(NSInteger)type url:(NSString *)url;

// Methods used to decrypt and read back values from a transaction hex string.
- (NSData *)dataFromHexString:(NSString *)hexString;

- (long long)dbIdFromData:(NSData*)data;
- (long long)secretFromData:(NSData*)data;

@end
