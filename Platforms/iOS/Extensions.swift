//
//  Extensions.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/7/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit

extension Point { var cgPoint: CGPoint { return CGPoint(CGFloat(x), CGFloat(y)) } }
extension CGPoint { var point: Point { return Point(Double(x), Double(y)) } }

extension Size { var cgSize: CGSize { return CGSize(width: width, height: height) } }
extension CGSize { var size: Size { return Size(width.Double, height.Double) } }

extension Rect { var cgRect: CGRect { return CGRect(x.CGFloat, y.CGFloat, width.CGFloat, height.CGFloat) } }
extension CGRect { var rect: Rect { return Rect(x.Double, y.Double, size.width.Double, size.height.Double) } }
