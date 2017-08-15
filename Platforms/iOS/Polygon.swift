//
//  Polygon.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/8/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

class Polygon : Entity {
    
    var vertices: [Point]
    var edges: [LineSegment] { return calculateEdges() }
    
    var sizeToFit: Size { return calculateSizeToFit() }
    
    init(vertices: [Point]) {
        
        self.vertices = vertices
        
        super.init()
    }
    
    func intersectsCircle(_ circle: Circle) -> [LineSegment]? {
        
        let edges = self.edges
        let circle = Circle(origin: circle.origin - position, radius: circle.radius)
        var segments: [LineSegment]?
        
        
        for edge in edges {
            
            if edge.distanceTo(circle.origin) < circle.radius {
                
                if segments == nil { segments = [edge] }
                else               { segments?.append(edge) }
            }
        }
        
        return segments
    }
    
    private func calculateEdges() -> [LineSegment] {
        
        return vertices.enumerated().map { offset, vertex in
            LineSegment(a: vertex, b: vertices[(offset + 1) % vertices.count])
        }
    }
    
    private func calculateSizeToFit() -> Size {
        
        var maxX: Double = 0
        var maxY: Double = 0
        
        vertices.forEach {
            
            if $0.x > maxX { maxX = $0.x }
            if $0.y > maxY { maxY = $0.y }
        }
        
        return Size(maxX, maxY)
    }
}

