/* This file is part of the KDE project
   Copyright (C) 2001 Andrea Rizzi <rizzi@kde.org>
	              Ulrich Kuettler <ulrich.kuettler@mailbox.tu-dresden.de>

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
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef KFORMULADOCUMENT_H
#define KFORMULADOCUMENT_H

#include <qdom.h>
#include <qobject.h>
#include <qptrlist.h>
#include <qstring.h>

#include <kaction.h>
#include <kcommand.h>
#include <kconfig.h>
#include <kocommandhistory.h>
//#include "kocommandhistory.h"
#include "kformuladefs.h"

KFORMULA_NAMESPACE_BEGIN

class ContextStyle;
class Container;
class SymbolTable;


/**
 * A document that can contain a lot of formulas (container).
 *
 * The relationship between the document and its formulas is an
 * open one. The document sure owns the formulas and when it
 * vanishes the formulas will be destroyed, too. But the user
 * will most often work with those formulas directly and not
 * bother to ask the document. It's legal to directly create
 * or destroy a Container object.
 */
class Document : public QObject {
    Q_OBJECT

    friend class Container;

public:

    /**
     * Creates a formula document with actions.
     *
     * @param collection a place to put the document's actions.
     * @param history the undo stack to use. Creates its own if zero.
     */
    Document( KConfig* config,
              KActionCollection* collection, KoCommandHistory* history = 0 );

    /**
     * Creates a formula document that doesn't use actions.
     *
     * @param history the undo stack to use. Creates its own if zero.
     */
    Document( KConfig* config, KoCommandHistory* history = 0 );

    ~Document();

    /**
     * Factory method.
     */
    virtual Container* createFormula( int pos=-1 );

    /**
     * Load a kformula DomDocument with all its formulas.
     * This must only be called on a virgin document.
     */
    bool loadXML( QDomDocument doc );

    /**
     * Load the document settings.
     */
    bool loadDocumentPart( QDomElement node );

    /**
     * Save the document with all its formulae.
     */
    QDomDocument saveXML();

    /**
     * Save the document settings.
     */
    QDomElement saveDocumentPart( QDomDocument doc );


    /**
     * @returns the documents context style.
     */
    ContextStyle& getContextStyle( bool edit=false );

    /**
     * Change the zoom factor to @p z (e.g. 150 for 150%)
     * and/or change the resolution, given in DPI.
     * Uses the KoZoomHandler.
     */
    void setZoomAndResolution( int zoom, int dpiX, int dpiY );

    void newZoomAndResolution( bool updateViews, bool forPrint );

    /**
     * Sets the zoom by hand. This is to be used in <code>paintContent</code>.
     */
    void setZoomAndResolution( int zoom, double zoomX, double zoomY,
                               bool updateViews=false, bool forPrint=false );

    double getXResolution() const;
    double getYResolution() const;

    /**
     * Sets a new formula.
     */
    void activate(Container* formula);

    /**
     * Enables our action according to enabled.
     */
    void setEnabled( bool enabled );

    /**
     * @returns our undo stack so the formulas can use it.
     */
    KoCommandHistory* getHistory() const;

    void undo();
    void redo();

    /**
     * @returns the documents symbol table
     */
    const SymbolTable& getSymbolTable() const;

    KAction* getAddNegThinSpaceAction();
    KAction* getAddThinSpaceAction();
    KAction* getAddMediumSpaceAction();
    KAction* getAddThickSpaceAction();
    KAction* getAddQuadSpaceAction();
    KAction* getAddBracketAction();
    KAction* getAddSBracketAction();
    KAction* getAddCBracketAction();
    KAction* getAddAbsAction();
    KAction* getAddFractionAction();
    KAction* getAddRootAction();
    KAction* getAddSumAction();
    KAction* getAddProductAction();
    KAction* getAddIntegralAction();
    KAction* getAddMatrixAction();
    KAction* getAddOneByTwoMatrixAction();
    KAction* getAddUpperLeftAction();
    KAction* getAddLowerLeftAction();
    KAction* getAddUpperRightAction();
    KAction* getAddLowerRightAction();
    KAction* getAddGenericUpperAction();
    KAction* getAddGenericLowerAction();
    KAction* getAddOverlineAction();
    KAction* getAddUnderlineAction();
    KAction* getAddMultilineAction();
    KAction* getRemoveEnclosingAction();
    KAction* getMakeGreekAction();
    KAction* getInsertSymbolAction();

    KAction* getAppendColumnAction();
    KAction* getInsertColumnAction();
    KAction* getRemoveColumnAction();
    KAction* getAppendRowAction();
    KAction* getInsertRowAction();
    KAction* getRemoveRowAction();

    KSelectAction* getLeftBracketAction();
    KSelectAction* getRightBracketAction();
    KSelectAction* getSymbolNamesAction();
    KToggleAction* getSyntaxHighlightingAction();
    KToggleAction* getFormatBoldAction();
    KToggleAction* getFormatItalicAction();

    KSelectAction* getFontFamilyAction();

    SymbolType leftBracketChar() const;
    SymbolType rightBracketChar() const;

    /**
     * Gets called when the configuration changed.
     * (Maybe we can find a better solution.)
     */
    void updateConfig();

    /**
     * Return a kformula DomDocument.
     */
    static QDomDocument createDomDocument();

public slots:

    void paste();
    void copy();
    void cut();

    void addNegThinSpace();
    void addThinSpace();
    void addMediumSpace();
    void addThickSpace();
    void addQuadSpace();
    void addDefaultBracket();
    void addBracket( SymbolType left, SymbolType right );
    void addParenthesis();
    void addSquareBracket();
    void addCurlyBracket();
    void addLineBracket();
    void addFraction();
    void addRoot();
    void addIntegral();
    void addProduct();
    void addSum();
    void addMatrix( uint rows=0, uint columns=0 );
    void addOneByTwoMatrix();
    void addNameSequence();
    void addLowerLeftIndex();
    void addUpperLeftIndex();
    void addLowerRightIndex();
    void addUpperRightIndex();
    void addGenericLowerIndex();
    void addGenericUpperIndex();
    void addOverline();
    void addUnderline();
    void addMultiline();
    void removeEnclosing();
    void makeGreek();
    void insertSymbol();
    void insertSymbol( QString name );

    void appendColumn();
    void insertColumn();
    void removeColumn();
    void appendRow();
    void insertRow();
    void removeRow();

    void toggleSyntaxHighlighting();
    void textBold();
    void textItalic();
    void delimiterLeft();
    void delimiterRight();
    void symbolNames();

    void fontFamily();

public:

    /**
     * @returns an iterator for the collection of formulas.
     */
    QPtrListIterator<Container> formulas();

protected:

    /**
     * @returns the internal position of this formula or -1 if it
     * doesn't belong to us.
     */
    int formulaPos( Container* formula );

    /**
     * @returns the formula at position pos.
     */
    Container* formulaAt( uint pos );

    /**
     * @returns the number of formulas in this document.
     */
    int formulaCount();

    /**
     * Registers a new formula to be part of this document. Each formula
     * must be part of exactly one document.
     *
     * The formula is not owned by the document so you are responsible
     * to delete in properly.
     */
    void registerFormula( Container*, int pos );

    /**
     * Tells that a formula is about to vanish. This must not be
     * the active formula from now on.
     */
    void formulaDies( Container* formula );

private:

    /**
     * Return the formula with the given number or create a new one
     * if there is no such formula.
     */
    Container* newFormula( uint number );

    /**
     * Needs to be called when the first formula is created.
     * The zoom functions must work before lazyInit was called.
     */
    void lazyInit();

    void initSymbolNamesAction();

    /**
     * Creates the standard formula actions and puts them into
     * the collection.
     */
    void createActions(KActionCollection* collection);

    /**
     * @returns whether we have a formula that can get requests.
     */
    bool hasFormula();

    /**
     * recalc all formulae.
     */
    void recalc();

    /**
     * @returns the active formula.
     */
    Container* formula() const;

    struct Document_Impl;
    Document_Impl* impl;
};

KFORMULA_NAMESPACE_END

#endif // KFORMULADOCUMENT_H
