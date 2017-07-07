//
//  Snapshotter.h
//  QLVideo
//
//  Created by Jonathan Harris on 13/07/2014.
//
//

#import <Cocoa/Cocoa.h>

#include "libavformat/avformat.h"


typedef NS_ENUM(NSInteger, CoverArtMode)
{
    CoverArtDefault     = 0,
    CoverArtThumbnail   = 1,
    CoverArtLandscape   = 2,
};


@interface Snapshotter : NSObject
{
    AVFormatContext *fmt_ctx;
    AVCodecContext *dec_ctx;
    AVCodecContext *enc_ctx;    // Only allocated if needed
    int stream_idx;             // index of "best" video stream
    int _thumbnails;        // "best" video stream is pre-computed thumbnails (i.e. DRMed content)
    int _channels;              // number of audio channels - purely for display
    NSString *_title;           // title for dsiplay
}

- (instancetype) initWithURL:(CFURLRef)url;
- (void) dealloc;
- (CGSize) displaySize;
- (NSInteger) duration;
- (CGImageRef) newCoverArtWithMode:(CoverArtMode)mode;
- (CFDataRef) newCoverArtAsCFDataRefWithMode:(CoverArtMode)mode;
- (CGImageRef) newSnapshotWithSize:(CGSize)size atTime:(NSInteger)seconds;
- (CFDataRef) newPNGWithSize:(CGSize)size atTime:(NSInteger)seconds;

@property (nonatomic,assign,readonly) int thumbnails;
@property (nonatomic,assign,readonly) int channels;
@property (nonatomic,retain,readonly) NSString *title;

@end
