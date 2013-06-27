//
//  MobeyInstance.h
//  iMobey
//
//  Created by ytf on 16/08/11.
//  Copyright 2011 InTech S.A.. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FlashizPaymentLib/MBProgressHUD.h>


@interface MobeyInstance : NSObject <MBProgressHUDDelegate>{
    
    NSNumber *balance;
    BOOL lockApplication;
    NSString *token;
    NSString *userName;
    NSMutableArray *queuedTransactions;
    BOOL hideTransactionsHistory;
    NSDictionary *labels;
}

@property(nonatomic,retain)  NSNumber *balance;
@property(nonatomic)  BOOL lockApplication;
@property(nonatomic,retain)   NSString *token;
@property(nonatomic,retain) NSString *userName;
@property(nonatomic,retain)NSMutableArray *queuedTransactions;
@property(nonatomic) BOOL hideTransactionsHistory;
@property(nonatomic,retain) NSDictionary *labels;
@property(nonatomic,retain) MBProgressHUD *HUD;

+(MobeyInstance *)sharedMobeyInstance;
+(UIImage *)doImageWithByteArray:(NSArray *)byteArray;
+(UIImage *)getCardImage:(NSString *)name;
+(void)saveImage:(UIImage *)image withName:(NSString *)name;
-(void)showHUDin:(UIViewController *)sender withMessage:(NSString *)message andTitle:(NSString *)title;
-(void)hideHUD;
+(NSString *)changeDate:(NSString *)date;
+(void)setLabelsForView:(UIView *)view;
+(NSString *)getLabelsValueForKey:(NSString *)key OrComment:(NSString *)comment;

@end
