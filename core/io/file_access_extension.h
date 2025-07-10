/**************************************************************************/
/*  file_access_extension.h                                               */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef FILE_ACCESS_EXTENSION_H
#define FILE_ACCESS_EXTENSION_H

#include "core/io/file_access.h"
#include "core/object/gdvirtual.gen.inc"
#include "core/object/object.h"

#ifndef GDVIRTUAL_REQUIRED_CALL
#define GDVIRTUAL_REQUIRED_CALL GDVIRTUAL_CALL
#endif

class FileAccessExtension : public FileAccess {
	GDCLASS(FileAccessExtension, FileAccess);

protected:
	static void _bind_methods();

private:
	GDVIRTUAL1R_REQUIRED(BitField<UnixPermissionFlags>, __get_unix_permissions, String);
	virtual BitField<UnixPermissionFlags> _get_unix_permissions(const String &p_file) override;
	GDVIRTUAL2R_REQUIRED(Error, __set_unix_permissions, String, BitField<UnixPermissionFlags>);
	virtual Error _set_unix_permissions(const String &p_file, BitField<UnixPermissionFlags> p_permissions) override;

	GDVIRTUAL1R_REQUIRED(bool, __get_hidden_attribute, String);
	virtual bool _get_hidden_attribute(const String &p_file) override;
	GDVIRTUAL2R_REQUIRED(Error, __set_hidden_attribute, String, bool);
	virtual Error _set_hidden_attribute(const String &p_file, bool p_hidden) override;
	GDVIRTUAL1R_REQUIRED(bool, __get_read_only_attribute, String);
	virtual bool _get_read_only_attribute(const String &p_file) override;
	GDVIRTUAL2R_REQUIRED(Error, __set_read_only_attribute, String, bool);
	virtual Error _set_read_only_attribute(const String &p_file, bool p_ro) override;

	GDVIRTUAL2R_REQUIRED(Error, _open_internal, String, int);
	virtual Error open_internal(const String &p_path, int p_mode_flags) override;
	GDVIRTUAL1R_REQUIRED(uint64_t, __get_modified_time, String);
	virtual uint64_t _get_modified_time(const String &p_file) override;
	GDVIRTUAL1R_REQUIRED(uint64_t, __get_access_time, String);
	virtual uint64_t _get_access_time(const String &p_file) override;
	GDVIRTUAL1R_REQUIRED(int64_t, __get_size, String);
	virtual int64_t _get_size(const String &p_file) override;

public:
	GDVIRTUAL0RC_REQUIRED(bool, _is_open);
	virtual bool is_open() const override;

	GDVIRTUAL0RC(String, _get_path);
	virtual String get_path() const override;
	GDVIRTUAL0RC(String, _get_path_absolute);
	virtual String get_path_absolute() const override;

	GDVIRTUAL1_REQUIRED(_seek, uint64_t);
	virtual void seek(uint64_t p_position) override;
	GDVIRTUAL1_REQUIRED(_seek_end, int64_t);
	virtual void seek_end(int64_t p_position) override;
	GDVIRTUAL0RC_REQUIRED(uint64_t, _get_position);
	virtual uint64_t get_position() const override;
	GDVIRTUAL0RC_REQUIRED(uint64_t, _get_length);
	virtual uint64_t get_length() const override;

	GDVIRTUAL0RC_REQUIRED(bool, _eof_reached);
	virtual bool eof_reached() const override;

	GDVIRTUAL0RC_REQUIRED(uint8_t, _get_8);
	virtual uint8_t get_8() const override;
	GDVIRTUAL0RC(uint16_t, _get_16);
	virtual uint16_t get_16() const override;
	GDVIRTUAL0RC(uint32_t, _get_32);
	virtual uint32_t get_32() const override;
	GDVIRTUAL0RC(uint64_t, _get_64);
	virtual uint64_t get_64() const override;

	GDVIRTUAL0RC(float, _get_float);
	virtual float get_float() const override;
	GDVIRTUAL0RC(double, _get_double);
	virtual double get_double() const override;
	GDVIRTUAL0RC(real_t, _get_real);
	virtual real_t get_real() const override;

	GDVIRTUAL1RC(Variant, _get_var, bool);
	Variant get_var(bool p_allow_objects = false) const;

	virtual uint64_t get_buffer(uint8_t *p_dst, uint64_t p_length) const override;
	GDVIRTUAL1RC(Vector<uint8_t>, _get_buffer, int64_t);
	Vector<uint8_t> get_buffer(int64_t p_length) const;
	GDVIRTUAL0RC(String, _get_line);
	virtual String get_line() const override;
	GDVIRTUAL0RC(String, _get_token);
	virtual String get_token() const override;
	GDVIRTUAL1RC(Vector<String>, _get_csv_line, String);
	virtual Vector<String> get_csv_line(const String &p_delim = ",") const override;
	GDVIRTUAL1RC(String, _get_as_text, bool);
	String get_as_text(bool p_skip_cr = false) const;
	GDVIRTUAL1RC(String, _get_as_utf8_string, bool);
	virtual String get_as_utf8_string(bool p_skip_cr = false) const override;

	GDVIRTUAL0RC_REQUIRED(Error, _get_error);
	virtual Error get_error() const override;

	GDVIRTUAL1R_REQUIRED(Error, _resize, int64_t);
	virtual Error resize(int64_t p_length) override;
	GDVIRTUAL0_REQUIRED(_flush);
	virtual void flush() override;
	GDVIRTUAL1R_REQUIRED(bool, _store_8, uint8_t);
	virtual bool store_8(uint8_t p_dest) override;
	GDVIRTUAL1R(bool, _store_16, uint16_t);
	virtual bool store_16(uint16_t p_dest) override;
	GDVIRTUAL1R(bool, _store_32, uint32_t);
	virtual bool store_32(uint32_t p_dest) override;
	GDVIRTUAL1R(bool, _store_64, uint64_t);
	virtual bool store_64(uint64_t p_dest) override;

	GDVIRTUAL1R(bool, _store_float, float);
	virtual bool store_float(float p_dest) override;
	GDVIRTUAL1R(bool, _store_double, double);
	virtual bool store_double(double p_dest) override;
	GDVIRTUAL1R(bool, _store_real, real_t);
	virtual bool store_real(real_t p_real) override;

	GDVIRTUAL1R(bool, _store_string, String);
	virtual bool store_string(const String &p_string) override;
	GDVIRTUAL1R(bool, _store_line, String);
	virtual bool store_line(const String &p_line) override;
	GDVIRTUAL2R(bool, _store_csv_line, Vector<String>, String);
	virtual bool store_csv_line(const Vector<String> &p_values, const String &p_delim = ",") override;

	GDVIRTUAL1R(bool, _store_pascal_string, String);
	virtual bool store_pascal_string(const String &p_string) override;
	GDVIRTUAL0RC(String, _get_pascal_string);
	virtual String get_pascal_string() override;

	virtual bool store_buffer(const uint8_t *p_src, uint64_t p_length) override;
	GDVIRTUAL1R(bool, _store_buffer, Vector<uint8_t>);
	bool store_buffer(const Vector<uint8_t> &p_buffer);

	GDVIRTUAL2R(bool, _store_var, Variant, bool);
	bool store_var(const Variant &p_var, bool p_full_objects = false);

	GDVIRTUAL0_REQUIRED(_close);
	virtual void close() override;

	GDVIRTUAL1R_REQUIRED(bool, _file_exists, String);
	virtual bool file_exists(const String &p_name) override;

	GDVIRTUAL2R(Error, _reopen, String, int);
	virtual Error reopen(const String &p_path, int p_mode_flags) override;

	FileAccessExtension();
	~FileAccessExtension();
};

#endif // FILE_ACCESS_EXTENSION_H
