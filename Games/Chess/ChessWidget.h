/*
 * Copyright (c) 2020, the SerenityOS developers.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "Chess.h"
#include <AK/HashMap.h>
#include <AK/NonnullRefPtr.h>
#include <AK/StringView.h>
#include <LibGUI/Widget.h>
#include <LibGfx/Bitmap.h>

class ChessWidget final : public GUI::Widget {
    C_OBJECT(ChessWidget)
public:
    ChessWidget();
    ChessWidget(const StringView& set);
    virtual ~ChessWidget() override;

    virtual void paint_event(GUI::PaintEvent&) override;
    virtual void resize_event(GUI::ResizeEvent&) override;
    virtual void mousedown_event(GUI::MouseEvent&) override;
    virtual void mouseup_event(GUI::MouseEvent&) override;
    virtual void mousemove_event(GUI::MouseEvent&) override;

    Chess& board() { return m_board; };

    Chess::Colour side() const { return m_side; };
    void set_side(Chess::Colour side) { m_side = side; };

    void set_piece_set(const StringView& set);
    const String& piece_set() const { return m_piece_set; };

    Chess::Square mouse_to_square(GUI::MouseEvent& event) const;

private:
    Chess m_board;
    Color m_dark_square_color { Color::from_rgb(0xb58863) };
    Color m_light_square_color { Color::from_rgb(0xf0d9b5) };
    Chess::Colour m_side { Chess::Colour::White };
    HashMap<Chess::Piece, RefPtr<Gfx::Bitmap>> m_pieces;
    String m_piece_set;
    Chess::Square m_moving_square { 50, 50 };
    Gfx::IntPoint m_drag_point;
    bool m_dragging_piece { false };
};