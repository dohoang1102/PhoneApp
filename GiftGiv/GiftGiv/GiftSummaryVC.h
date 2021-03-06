//
//  GiftSummaryVC.h
//  GiftGiv
//
//  Created by Srinivas G on 01/08/12.
//  Copyright (c) 2012 Teleparadigm Networks Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SuccessVC.h"

#import "PayPal.h"
#import "SetExpressCheckoutRequestDetails.h"
#import "ECNetworkHandler.h"
#import "WebViewController.h"
#import "PaymentDetails.h"

#import "MBProgressHUD.h"


//ExpressCheckoutResponseHandler is not part of the Express Checkout library and should
//generally not be used because doing the Express Checkout calls on the device requires
//that the merchant API credentials be stored in the executable, which is a security risk.


@interface GiftSummaryVC : UIViewController<ExpressCheckoutResponseHandler,DeviceReferenceTokenDelegate,MBProgressHUDDelegate>{
    MBProgressHUD *HUD;
}

@property (retain, nonatomic) IBOutlet UIScrollView *giftSummaryScroll;
@property (retain, nonatomic) IBOutlet UIImageView *profilePic;
@property (retain, nonatomic) IBOutlet UILabel *profileNameLbl;
@property (retain, nonatomic) IBOutlet UILabel *eventNameLbl;
@property (retain, nonatomic) IBOutlet UIImageView *giftImg;
@property (retain, nonatomic) IBOutlet UILabel *giftNameLbl;
@property (retain, nonatomic) IBOutlet UILabel *giftPriceLbl;
@property (retain, nonatomic) IBOutlet UILabel *addressLbl;
@property (retain, nonatomic) IBOutlet UILabel *mailGiftToLbl;
@property (retain, nonatomic) IBOutlet UILabel *personalMsgLbl;
@property (retain, nonatomic) IBOutlet UILabel *recipientAddressHeadLbl;
@property (retain, nonatomic) IBOutlet UILabel *paymentBtnLbl;
@property (retain, nonatomic) IBOutlet UIButton *paymentBtn;
@property (retain, nonatomic) IBOutlet UILabel *disclosureLbl;

@property (retain, nonatomic) NSMutableDictionary *giftSummaryDict;
@property (retain, nonatomic) IBOutlet UILabel *msgHeadLbl;

- (IBAction)backToRecipientForm:(id)sender;
- (IBAction)paymentBtnAction:(id)sender;

- (void)loadGiftImage:(NSString*)imgURL forAnObject:(UIImageView*)targetImgView;

#pragma mark - progress hud
- (void) showProgressHUD:(UIView *)targetView withMsg:(NSString *)titleStr;
- (void)stopHUD;
#pragma mark -
@end
