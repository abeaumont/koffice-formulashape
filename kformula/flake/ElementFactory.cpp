/* This file is part of the KDE project
   Copyright (C) 2003 Ulrich Kuettler <ulrich.kuettler@gmx.de>
                 2006 Martin Pfeiffer <hubipete@gmx.net>
                 2006 Alfredo Beaumont Sainz <alfredo.beaumont@gmail.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "ElementFactory.h"

//#include "ActionElement.h"
//#include "BracketElement.h"
//#include "EncloseElement.h"
//#include "ErrorElement.h"
#include "FractionElement.h"
//#include "GlyphElement.h"
//#include "IdentifierElement.h"
//#include "MatrixElement.h"
//#include "MatrixRowElement.h"
//#include "MatrixEntryElement.h"
//#include "MultiscriptElement.h"
//#include "NumberElement.h"
//#include "OperatorElement.h"
//#include "PaddedElement.h"
//#include "PhantomElement.h"
//#include "RootElement.h"
#include "RowElement.h"
#include "SpaceElement.h"
//#include "StringElement.h"
//#include "StyleElement.h"
//#include "TextElement.h"
//#include "UnderOverElement.h"

namespace FormulaShape {

BasicElement* ElementFactory::createElement( const QString& tagName,
                                             BasicElement* parent )
{
    //    if( tagName == "mi" )
    //        return new IdentifierElement( parent );
    //else if ( tagName == "mo" )           
    //        return new OperatorElement( parent );
    //else if ( tagName == "mn" )
    //        return new NumberElement( parent );
    //else if ( tagName == "mtext" )
    //        return new TokenElement( parent );
    //else if ( tagName == "ms" )
    //        return new StringElement( parent );
/*  else*/ if ( tagName == "mspace" )
        return new SpaceElement( parent );
    //else if ( tagName == "mglyph" )
    //        return new GlyphElement( parent );
     else if ( tagName == "mrow" )
          return new RowElement( parent );
     else if ( tagName == "mfrac" )  
          return new FractionElement( parent );
    //else if ( tagName == "msqrt" || tagName == "mroot" )
    //      return new RootElement( parent );
    //else if ( tagName == "mstyle" )
    //      return new StyleElement( parent );
    //else if ( tagName == "merror" ) 
    //      return new ErrorElement( parent );
    //else if ( tagName == "mpadded" )  
    //      return new PaddedElement( parent );
    //else if ( tagName == "mphantom" )
    //      return new PhantomElement( parent );
    //else if ( tagName == "mfenced" )
    //      return new BracketElement( parent );
    //else if ( tagName == "menclose" )
    //      return new EncloseElement( parent );
    //else if ( tagName == "msub" || tagName == "msup" || tagName == "msubsup" )
    //      return new MultiscriptElement( parent );
    //else if ( tagName == "munder" || tagName == "mover" || tagName == "munderover" )
    //      return new UnderOverElement( parent );
    //else if ( tagName == "mmultiscripts" )
    //      return new MultiscriptElement( parent );

    return 0;
}

} // namespace FormulaShape