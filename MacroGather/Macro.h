//
//  Macro.h
//  MacroGather
//
//  Created by Teonardo on 2019/7/22.
//  Copyright © 2019 Teonardo. All rights reserved.
//

/******************************************
 * 宏命名说明:
 * 全局常量,单词大写以下划线分割
 * 全局方法(带参数),首字母大写+驼峰命名法
 ******************************************/


#ifndef Macro_h
#define Macro_h

// ====================== 屏幕尺寸 ======================
/* 屏幕的宽度, 也即视图控制器的 view 的宽度 */

#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)

/* 屏幕的高度, 也即视图控制器的 view 的高度 */

#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

/* 状态栏高度. 在 iPhone X 机型上由于齐刘海的设计, 状态栏的高度比一般机型的要多24PT, 为44 PT */

#define STATUS_BAR_SAFE_HEIGHT (IS_IPHONE_X ? 44.f : 20.f)

/* 导航栏的高度 */

#define NAVIGATION_BAR_HEIGHT (44.f)

/* 标签栏的高度 */

#define TAB_BAR_HEIGHT (49.f)

/* 导航栏底部到屏幕顶部的距离 */

#define NAVIGATION_BAR_MAX_Y (STATUS_BAR_SAFE_HEIGHT + NAVIGATION_BAR_HEIGHT)

/* Home指示器的高度 */

#define HOME_INDICATOR_HEIGHT (34.f)

/* 安全区到屏幕底部的距离. 在 iPhone X 机型上由于底部 Home Indicator 的存在, 需留出相应距离 */

#define SAFE_AREA_BOTTOM_INSET (IS_IPHONE_X ? HOME_INDICATOR_HEIGHT : 0.f)


// ====================== 设备类型 ======================
/* 是否是 iPad 设备 */

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

/* 是否是 iPhone 设备 */

#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

/* 是否是 iPhoneX */

#define IS_IPHONE_X (\
UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && \
MAX(SCREEN_WIDTH, SCREEN_HEIGHT) == 812.0f \
|| MAX(SCREEN_WIDTH, SCREEN_HEIGHT) == 896.0f)


// ====================== 颜色 ======================
/* 通过 RGB 以及 alpha 值获取颜色 */

#define ColorWithRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

/* 通过 RGB 来获取颜色, 默认alpha为 1.0 */

#define ColorWithRGB(r, g, b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1.0]

/* 通过 十六进制值 以及 alpha 值来获取颜色 (不需传 0x 符号) */

#define ColorWithHexA(hexValue, alp) [UIColor \
colorWithRed:((float)((0x##hexValue & 0xFF0000) >> 16))/255.0 \
green:((float)((0x##hexValue & 0xFF00) >> 8))/255.0 \
blue:((float)(0x##hexValue & 0xFF))/255.0 alpha:alp]

/* 通过 十六进制值 来获取颜色, 默认alpha为 1.0 (不需传 0x 符号) */

#define ColorWithHex(hexValue) ColorWithHexA(hexValue, 1.0f)

/* 获取一个随机颜色 */

#define RandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

// ====================== Log ======================
#ifdef DEBUG
#define NSLog(format, ...) do {\
fprintf(stderr, "<%s : %d> %s\n",\
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],\
__LINE__, __func__);\
(NSLog)((format), ##__VA_ARGS__);\
fprintf(stderr, "-------\n");\
} while (0)
#else
#define NSLog(...)
#endif

// ====================== 适配 ======================
/* 将指定给定宽度参照 iPhone 6s 的宽度进行等比缩放 */

#define AdaptedWidth(w) ceilf((w) * SCREEN_WIDTH / 375.f)

/* 将给定高度参照 iPhone 6s 的高度进行等比缩放 */

#define AdaptedHeight(h) ceilf((h) * SCREEN_HEIGHT / 667.f)

/* 字体大小适配, 参照 iPhone 6s进行变化. 如果屏幕尺寸大于6s的, 则字体大小加上1PT; 如果屏幕尺寸小于6s的, 则字体大小减去1PT */

#define AdaptedFontSize(s) (SCREEN_WIDTH == 320 ? (s) : (SCREEN_WIDTH > 320 ? ((s) + 1.f) : ((s) - 1.f)))

/* 字体适配, 参照 iPhone 6s进行变化. 如果屏幕尺寸大于6s的, 则字体大小加上1PT; 如果屏幕尺寸小于6s的, 则字体大小减去1PT */

#define AdaptedFont(size) [UIFont systemFontOfSize:AdaptedFontSize(size)]

// ====================== 系统 ======================

/* UserDefaults */

#define UserDefaults [NSUserDefaults standardUserDefaults]


#endif /* Macro_h */
