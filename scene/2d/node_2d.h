/*************************************************************************/
/*  node_2d.h                                                            */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2017 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2017 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef NODE2D_H
#define NODE2D_H

#include "scene/2d/canvas_item.h"

class Node2D : public CanvasItem {

	GDCLASS(Node2D, CanvasItem);

	Point2 pos;
	float angle;
	Size2 _scale;
	int z;
	bool z_relative;

	Transform2D _mat;

	bool _xform_dirty;

	void _update_transform();

	// Deprecated, should be removed in a future version.
	void _set_rotd(float p_angle);
	float _get_rotd() const;

	void _update_xform_values();

protected:
	void _notification(int p_what);

	static void _bind_methods();

public:
	virtual Variant edit_get_state() const;
	virtual void edit_set_state(const Variant &p_state);
	virtual void edit_set_rect(const Rect2 &p_edit_rect);
	virtual void edit_rotate(float p_rot);
	virtual void edit_set_pivot(const Point2 &p_pivot);
	virtual Point2 edit_get_pivot() const;
	virtual bool edit_has_pivot() const;

	void set_position(const Point2 &p_pos);
	void set_rotation(float p_radians);
	void set_rotation_in_degrees(float p_degrees);
	void set_scale(const Size2 &p_scale);

	void rotate(float p_radians);
	void move_x(float p_delta, bool p_scaled = false);
	void move_y(float p_delta, bool p_scaled = false);
	void translate(const Vector2 &p_amount);
	void global_translate(const Vector2 &p_amount);
	void apply_scale(const Size2 &p_amount);

	Point2 get_position() const;
	float get_rotation() const;
	float get_rotation_in_degrees() const;
	Size2 get_scale() const;

	Point2 get_global_position() const;
	float get_global_rotation() const;
	float get_global_rotation_in_degrees() const;
	Size2 get_global_scale() const;
	virtual Rect2 get_item_rect() const;

	void set_transform(const Transform2D &p_transform);
	void set_global_transform(const Transform2D &p_transform);
	void set_global_position(const Point2 &p_pos);
	void set_global_rotation(float p_radians);
	void set_global_rotation_in_degrees(float p_degrees);
	void set_global_scale(const Size2 &p_scale);

	void set_z(int p_z);
	int get_z() const;

	void look_at(const Vector2 &p_pos);
	float get_angle_to(const Vector2 &p_pos) const;

	Point2 to_local(Point2 p_global) const;
	Point2 to_global(Point2 p_local) const;

	void set_z_as_relative(bool p_enabled);
	bool is_z_relative() const;

	Transform2D get_relative_transform_to_parent(const Node *p_parent) const;

	Transform2D get_transform() const;

	Node2D();
};

#endif // NODE2D_H
