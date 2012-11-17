//
//  PSPDFTextParser.h
//  PSPDFKit
//
//  Copyright 2012 Peter Steinberger. All rights reserved.
//

#import "PSPDFKitGlobal.h"

@class PSPDFFontInfo, PSPDFGraphicsState, PSPDFHighlightAnnotation;

/// Parses the text of a PDF page.
@interface PSPDFTextParser : NSObject

/// Designated initializer.
/// fontCache is optional, share only between one PSPDFDocumentProvider.
// Page is just used to aid debugging. (absolute to PSPDFDocument)
- (id)initWithPDFPage:(CGPDFPageRef)pageRef page:(NSUInteger)page fontCache:(NSMutableDictionary *)fontCache hideGlyphsOutsidePageRect:(BOOL)hideGlyphsOutsidePageRect PDFBox:(CGPDFBox)PDFBox;

/// Complete page text.
@property (nonatomic, copy) NSString *text;

/// Uses glyphs to return the corresponding page text, including newlines and spaces.
- (NSString *)textWithGlyphs:(NSArray *)glyphs;

/// Complete list of PSPDFGlyph objects. Corresponds to the text.
@property (nonatomic, strong, readonly) NSMutableArray *glyphs;

/// List of detected words (PSPDFWord)
@property (nonatomic, strong, readonly) NSMutableArray *words;

/// List of detected text blocks (PSPDFTextBlock)
@property (nonatomic, copy, readonly) NSArray *textBlocks;

@end
