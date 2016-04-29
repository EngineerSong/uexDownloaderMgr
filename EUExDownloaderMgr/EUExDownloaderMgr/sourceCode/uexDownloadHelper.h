/**
 *
 *	@file   	: uexDownloadHelper.h  in EUExDownloaderMgr
 *
 *	@author 	: CeriNo 
 * 
 *	@date   	: Created on 16/4/18.
 *
 *	@copyright 	: 2016 The AppCan Open Source Project.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#import <Foundation/Foundation.h>
@class WWidget;
@class EUExDownloaderMgr;


#ifdef DEBUG
#define XCODE_DEBUG_MODE 1
#else 
#define XCODE_DEBUG_MODE 0
#endif

#define UEXLog(...) uexDownloadLog(__VA_ARGS__);


typedef NS_OPTIONS(NSInteger, uexDownloaderCancelOption){
    uexDownloaderCancelOptionDefault = 0,
    uexDownloaderCancelOptionClearCache = 1 << 0,
};




@interface uexDownloadHelper : NSObject

void uexDownloadLog(NSString *format,...);

+ (void)setDebugMode:(BOOL)mode;

+ (WWidget *)mainWidget;
+ (NSDictionary<NSString *,NSString *> *)AppCanHTTPHeadersWithEUExObj:(EUExDownloaderMgr *)euexObj;

+ (NSURLSessionAuthChallengeDisposition)authChallengeDispositionWithSession:(NSURLSession *)session
                                                                  challenge:(NSURLAuthenticationChallenge *)challenge
                                                                 credential:(NSURLCredential *__autoreleasing *)credential;

@end
@interface NSString (uexDownloaderMgr)
//获取MD5字符串
- (instancetype)uexDownloader_MD5;

@end

@interface NSDate (uexDownloaderMgr)
//NSDate的时间戳字符串
- (NSString *)uexDownloader_timestamp;

@end

@interface NSURL(uexDownloaderMgr)

+ (instancetype)uexDownloader_saveURLFromPath:(NSString *)savePath;
@end
