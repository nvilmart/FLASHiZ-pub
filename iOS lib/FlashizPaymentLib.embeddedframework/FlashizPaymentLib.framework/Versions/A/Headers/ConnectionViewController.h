//
//  ConnectionViewController.h
//  iMobey
//
//  Created by Fabrice CROISEAUX on 22/05/11.
//  Copyright 2011 InTech S.A.. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
//#import "PaymentViewController.h"
#import "PinCodeControllerView.h"
#import "MBProgressHUD.h"
@protocol ConnectionViewControllerDelegate;


@interface ConnectionViewController : UIViewController <PinCodeControllerViewDelegate,UITextFieldDelegate,UIAlertViewDelegate> {
    
	UITextField	*textFieldUser;
	UITextField	*textFieldPassword;
    BOOL firstTime;
    UITableView *loginTable;
    UIImageView *logoImg;
    UIImageView *labelStart;
    UIImageView *logoLeft;
    UIImageView *logoRight;
    UIButton *connectButton;
    UIImageView *headerImg;
    
    Reachability* internetReachable;
    Reachability* hostReachable;
    BOOL connectionOK;

}

@property (nonatomic, retain) IBOutlet UIImageView *headerImg;
@property (retain, nonatomic) IBOutlet UIButton *inscriptionButton;
@property (nonatomic, assign) id <ConnectionViewControllerDelegate> delegate;
@property (nonatomic, retain)IBOutlet UITextField	*textFieldUser;
@property (nonatomic, retain)IBOutlet UITextField	*textFieldPassword;
@property(nonatomic)BOOL firstTime;
@property (nonatomic, retain) IBOutlet UITableView *loginTable;
@property (nonatomic, retain) IBOutlet UIImageView *logoImg;
@property (nonatomic, retain) IBOutlet UIImageView *labelStart;
@property (nonatomic, retain) IBOutlet UIImageView *logoLeft;
@property (nonatomic, retain) IBOutlet UIImageView *logoRight;
@property (nonatomic, retain) IBOutlet UIButton *connectButton;
@property (retain, nonatomic) IBOutlet UIImageView *fond;
@property (retain, nonatomic) IBOutlet UIView *container;
@property (retain, nonatomic) UIViewController* customCell;


@property (retain, nonatomic) IBOutlet UIButton *createAccount;

- (IBAction)connect;
- (IBAction)close;
- (IBAction)inscriptionAction:(id)sender;
- (IBAction)cancelClicked:(id)sender;

- (void)checkConnection;
-(void)saveImageWithByteArray:(NSArray *)byteArray;
-(void)deleteAvatar;
+ (void)showConnectScreen:(id)sender;
+ (void)showConnectScreen:(id) sender firstTime:(BOOL)firstTime;
- (void) checkNetworkStatus:(NSNotification *)notice;
- (IBAction)inscriptionAction:(id)sender;

@end


@protocol ConnectionViewControllerDelegate
- (void)connectionControllerShouldRegister;
- (void)connectionControllerShouldEnterPinCodeWithInfos:(NSDictionary*) infos;
- (void)connectionControllerDidFinish;
- (void)connectionControllerCancel;
@end

