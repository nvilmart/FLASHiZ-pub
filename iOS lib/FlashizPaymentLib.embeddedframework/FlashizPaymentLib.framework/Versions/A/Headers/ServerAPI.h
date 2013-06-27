//
//  ServerAPI.h
//  iMobey
//
//  Created by Fabrice CROISEAUX on 22/05/11.
//  Copyright 2011 InTech S.A.. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobeyInstance.h"

@interface ServerAPI : NSObject {
    
     MobeyInstance *sharedInstance;
}

+ (NSString *) serverUrl;
+ (void) setServerUrl:(NSString*) url;
+ (void) initValues;
+ (NSString *)connect:(NSString *)theUser password:(NSString *)pwd firstTime:(BOOL)firstTime withDeviceName:(NSString *)device withDeviceName:(NSString *)name;
+ (NSString *)connectWithKey:(NSString *)userKey andPin:(NSString *)pin;
+ (NSString *)disconnect:(NSString *)userkey;
+ (NSString *)getAccount:(NSString *)userKey;
+ (NSString *)listPayments:(NSString *)userKey;
+ (NSString *)listTransactions:(NSString *)userKey;
+ (NSString *)readInvoice:(NSString *)invoiceId userKey:(NSString *)userKey;
+ (NSString *)payInvoice:(NSString *)invoiceId userKey:(NSString *)userKey;
+ (NSString *)createInvoice:(NSString *)userKey amount:(NSString *)amount;
+ (NSString *)checkPayment:(NSString *)invoiceId forUserKey:(NSString *)userKey;
+ (UIImage *)getAvatar;
+ (NSString *)getAvatarWithMail:(NSString *)userMail;
+ (NSString *)getAvatarWithUserName:(NSString *)userName;
+ (void)getAvatarWithUserNameAsync:(NSString *)mail delegate:(id)handler;
+ (NSString *)sendPIN:(NSString *)PIN withUserKey:(NSString *)userKey withToken:(NSString *)token;
+ (NSString *)checkPIN:(NSString *)PIN withUserKey:(NSString *)userKey;
+ (NSString *)changePIN:(NSString *)oldPIN toNewPIN:(NSString *)newPIN withUserKey:(NSString *)userKey;
+ (NSString *)transfertMoney:(NSString *)amount withComment:(NSString *)comment forUser:(NSString *)reciver fromUser:(NSString *)userKey withType:(NSString *)type;
+ (NSString *)findQueuedTransactionsreceiverWithUserKey :(NSString *)userKey;
+ (NSString *)executeTransactionsWithId :(NSString *)idTransaction forUser:(NSString *)userKey;
+ (NSString *)cancelTransactionsWithId :(NSString *)idTransaction forUser:(NSString *)userKey AndSide:(NSString *)side;
+ (NSString *)getUserInfos :(NSString *)userKey;
+ (BOOL)checkResult:(NSString *)result;
+ (void)deleteHTTPCookies;

@end

