//
//  PinCodeControllerView.h
//  iMobey
//
//  Created by ytf on 02/08/11.
//  Copyright 2011 InTech S.A.. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "ServerAPI.h"
#import "MobeyInstance.h"
#import "MBProgressHUD.h"
#import "Reachability.h"

@protocol PinCodeControllerViewDelegate;

@interface PinCodeControllerView : UIViewController <UITextFieldDelegate,UITextViewDelegate,UIAlertViewDelegate,MBProgressHUDDelegate>{
    
    BOOL passwordAlreadySet;
    BOOL forConnection;
    NSString *firsPassword;
    int errorCount;
    NSString *secondPassword;
    
    UITextField *first;
    UITextField *second;
    UITextField *third;
    UITextField *fourth;
    UILabel *titleLabel;
     UIButton *cancelButton;
    UILabel *indicatorLabel;
    UIView *firstTimeView;
    UIView *viewWithPassword;
    UILabel *firstName;
    UIImageView *logoRight;
    UILabel *lastName;
    UIImageView *avatar;
    UIImageView *labelStart;
    IBOutlet UIImageView *firsrtImg;
    IBOutlet UIImageView *secondImg;
    IBOutlet UIImageView *thirdImg;
    IBOutlet UIImageView *fourthImg;
     MBProgressHUD *HUD;
    MobeyInstance *sharedInstance;
    UIButton *logoutButton;
    UIButton *keyboardBackButton;
    UIButton *backButton;
    UIImageView *logoImg;
    UIImageView *headerImg;
    UIImageView *logoLeft;
    NSDictionary *infos;
    
    Reachability* internetReachable;
    Reachability* hostReachable;
    BOOL connectionOK;
    BOOL viewDeallocated;
}

@property (retain, nonatomic) IBOutlet UIView *container;
@property (retain, nonatomic) IBOutlet UIImageView *fond;

@property (nonatomic, retain) IBOutlet UIButton *logoutButton;
@property (nonatomic, retain) IBOutlet UIButton *keyboardBackButton;
@property (nonatomic, retain) IBOutlet UIButton *backButton;
@property (nonatomic, retain) IBOutlet UIImageView *logoImg;
@property (nonatomic, retain) IBOutlet UIImageView *headerImg;
@property (nonatomic, retain) IBOutlet UIImageView *logoLeft;
@property (nonatomic, retain) NSDictionary *infos;
@property (nonatomic, retain) IBOutlet UIView *viewWithPassword;
@property (nonatomic, retain) IBOutlet UILabel *firstName;
@property (nonatomic, retain) IBOutlet UIImageView *logoRight;
@property (nonatomic, retain) IBOutlet UILabel *lastName;
@property (nonatomic, retain) IBOutlet UIImageView *avatar;
@property (nonatomic, retain) IBOutlet UIImageView *labelStart;

@property (nonatomic, retain) IBOutlet UIView *firstTimeView;
@property (nonatomic, retain) IBOutlet UILabel *indicatorLabel;
@property (nonatomic) BOOL passwordAlreadySet;
@property (nonatomic) BOOL forConnection;
@property (nonatomic,retain)UIButton *cancelButton;
@property (nonatomic, retain) IBOutlet UITextField *first;
@property (nonatomic, retain) IBOutlet UITextField *second;
@property (nonatomic, retain) IBOutlet UITextField *third;
@property (nonatomic, retain) IBOutlet UITextField *fourth;
@property (nonatomic, retain) IBOutlet UILabel *titleLabel;
@property (nonatomic, retain) IBOutlet   NSString *firsPassword;
@property (nonatomic, retain) IBOutlet    NSString *secondPassword;
@property (nonatomic,assign)  id<PinCodeControllerViewDelegate> delegate;

- (IBAction)fourthNumber:(id)sender;
- (IBAction)firstNumber:(id)sender;
- (IBAction)thirdNumber:(id)sender;
- (IBAction)secondNumber:(id)sender;
- (IBAction)logout:(id)sender;
- (IBAction)back:(id)sender;

-(void)addkey;
-(void)passwordCompleted;
- (void)cancel;
-(void)animationDone;
-(void)doAnimation;
-(void)showWithoutAnimation;
-(void)checkFourthNumber;
-(void)disconnect;

+(void)showPINController:(UIViewController *)sender withPasswordAlreadySet:(BOOL)passwordAlreadySet forConnection:(BOOL)connect;
+(void)showPINController:(UIViewController *)sender withPasswordAlreadySet:(BOOL)passwordAlreadySet forConnection:(BOOL)connect withInfos:(NSDictionary *)infos;
- (void) checkNetworkStatus:(NSNotification *)notice;
-(void)showKey;
@end

typedef enum  {
    MPVC_OK,
    MPVC_INVALID,
    MPVC_CANCELED,
    MPVC_ERROR,
    MPVC_NOT_ENOUGH_MONEY
} makePaymentStatus;

@protocol PinCodeControllerViewDelegate <NSObject>
@optional
-(void) passwordSet;
-(void) disconnected;
- (void)pinCancelPushed;
- (void)makePaymentViewControllerDidFinishWithStatus:(makePaymentStatus) status;
@end