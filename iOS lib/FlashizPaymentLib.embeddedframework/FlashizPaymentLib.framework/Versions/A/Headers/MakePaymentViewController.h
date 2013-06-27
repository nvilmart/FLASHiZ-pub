//
//  MakePaymentViewController.h
//  iMobey
//
//  Created by Fabrice CROISEAUX on 25/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PinCodeControllerView.h"
#import "MBProgressHUD.h"
#import "MobeyInstance.h"

@protocol MakePaymentViewControllerDelegate;

@interface MakePaymentViewController : UIViewController <UIActionSheetDelegate,UIAlertViewDelegate,MBProgressHUDDelegate> {
    
    @private
    
    NSMutableData* avatarData;
    NSString* rcvUsrNme;
    
    NSString *scannedId;
    UILabel *userName;
    UILabel *signEuroAfterBalance;
	UILabel *transactionId;
	UILabel	*amount;	
    UILabel *comment;
    UILabel *currentBalance;
    UILabel *afterBalance;
    UILabel *receiver;
    UIButton *confirmButton;
    UIButton *cancelButton;
    UIImageView *userAvatar;
    
    MobeyInstance *sharedInstance;
    NSString *theNewBalanceData;
    
    MBProgressHUD *HUD;
}

@property (nonatomic, retain) IBOutlet UIButton *confirmButton;
@property (nonatomic, retain) IBOutlet UIButton *cancelButton;
@property (nonatomic, retain) IBOutlet UIImageView *userAvatar;
//@property (nonatomic, retain) NewCreditCardViewController *otherNewCreditCardView;
//@property (nonatomic, retain) CreditCardViewController *creditCardView;
@property (nonatomic, assign)id<MakePaymentViewControllerDelegate>delegate;
@property (nonatomic, retain)IBOutlet UILabel *transactionId;
@property (nonatomic, retain)IBOutlet UILabel *amount;
@property (nonatomic, retain)IBOutlet UILabel *comment;
@property (nonatomic, retain)IBOutlet UILabel *currentBalance;
@property (nonatomic, retain)IBOutlet UILabel *afterBalance;
@property (nonatomic, retain)IBOutlet UILabel *receiver;
@property (nonatomic, retain) NSString *scannedId;
@property (nonatomic, retain) IBOutlet UILabel *userName;
@property (nonatomic, retain) IBOutlet UILabel *signEuroAfterBalance;
@property (retain, nonatomic) IBOutlet UIImageView *receiverAvatar;

@property (retain, nonatomic) IBOutlet UILabel *lblAutoRefill;
@property (nonatomic, retain) IBOutlet NSString *theNewBalanceData;


- (IBAction)validatePIN;

+ (void)showScreen:(id) sender invoiceId: (NSString *) theInvoiceId;
- (void) readInvoice:(NSString *)invoiceId;
-(void)doValidation;

@end


@protocol MakePaymentViewControllerDelegate <NSObject>

- (void)makePaymentViewControllerDidFinishWithStatus:(makePaymentStatus) status;

@end
