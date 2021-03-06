//
//  RMessageView.h
//  RMessage
//
//  Created by Adonis Peralta on 12/7/15.
//  Copyright © 2015 Rendezvous Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RMessage.h"

@protocol RMessageViewProtocol <NSObject>

- (void)messageViewDidPresent:(RMessageView *)messageView;

- (void)messageViewDidDismiss:(RMessageView *)messageView;

- (CGFloat)customVerticalOffsetForMessageView:(RMessageView *)messageView;

- (void)windowChangedForMessageView:(RMessageView *)messageView;

- (void)didSwipeToDismissMessageView:(RMessageView *)messageView;

- (void)didTapMessageView:(RMessageView *)messageView;

@end

@interface RMessageView : UIView

@property (nonatomic, weak) id <RMessageViewProtocol> delegate;

/** The displayed title of this message */
@property (nonatomic, readonly) NSString *title;

/** The displayed subtitle of this message */
@property (nonatomic, readonly) NSString *subtitle;

/** The view controller this message is displayed in */
@property (nonatomic, readonly) UIViewController *viewController;

/** The duration of the displayed message. If it is 0.0, it will automatically be calculated */
@property (nonatomic, assign) CGFloat duration;

/** The position of the message (top or bottom) */
@property (nonatomic, assign) RMessagePosition messagePosition;

/** The opacity of the message view */
@property (nonatomic, assign, readonly) CGFloat messageOpacity;

/** Is the message currently fully displayed? Is set as soon as the message is really fully visible */
@property (nonatomic, assign) BOOL messageIsFullyDisplayed;

/** Customize title font using Apperance */
@property (nonatomic, strong) UIFont *titleFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *titleTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *subtitleFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *subtitleTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *messageIcon UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *errorIcon UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *successIcon UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *warningIcon UI_APPEARANCE_SELECTOR;

/** Inits the message view. Do not call this from outside this library.
 @param title The title of the message view
 @param subtitle The subtitle of the message view (optional)
 @param iconImage A custom icon image (optional)
 @param messageType The type of message view
 @param duration The duration this notification should be displayed (optional)
 @param viewController The view controller this message should be displayed in
 @param callback The block that should be executed, when the user tapped on the message
 @param buttonTitle The title for button (optional)
 @param buttonCallback The block that should be executed, when the user tapped on the button
 @param position The position of the message on the screen
 @param dismissingEnabled Should this message be dismissed when the user taps/swipes it?
 */
- (instancetype)initWithDelegate:(id<RMessageViewProtocol>)delegate
                           title:(NSString *)title
                        subtitle:(NSString *)subtitle
                       iconImage:(UIImage *)iconImage
                            type:(RMessageType)messageType
                customTypeString:(NSString *)customTypeString
                        duration:(CGFloat)duration
                inViewController:(UIViewController *)viewController
                        callback:(void (^)())callback
                     buttonTitle:(NSString *)buttonTitle
                  buttonCallback:(void (^)())buttonCallback
                      atPosition:(RMessagePosition)position
            canBeDismissedByUser:(BOOL)dismissingEnabled;

/** Use this method to load a custom design file */
+ (void)addDesignFromFile:(NSString *)file;

/** Execute the message view call back if set */
- (void)executeMessageViewCallBack;

/** Execute the message view button call back if set */
- (void)executeMessageViewButtonCallBack;

- (void)present;

- (void)dismissWithCompletion:(void (^) (void))completionBlock;

///** Indicates whether the current navigationBar is hidden by isNavigationBarHidden
// on the UINavigationController or isHidden on the navigationBar of the current
// UINavigationController */
//+ (BOOL)isNavigationBarHiddenForNavigationController:(UINavigationController *)navController;

@end
