/* Code generated by cmd/cgo; DO NOT EDIT. */

/* package storj.io/uplink-c */


#line 1 "cgo-builtin-export-prolog"

#include <stddef.h> /* for ptrdiff_t below */

#ifndef GO_CGO_EXPORT_PROLOGUE_H
#define GO_CGO_EXPORT_PROLOGUE_H

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef struct { const char *p; ptrdiff_t n; } _GoString_;
#endif

#endif

/* Start of preamble from import "C" comments.  */


#line 6 "access.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "bucket.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "buckets.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "config.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 3 "custom_metadata_helper.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "download.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "encryption.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "error.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "main.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "object.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "objects.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "project.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 3 "restrict_scope_helper.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"

#line 6 "upload.go"
 #include "uplink_definitions.h"

#line 1 "cgo-generated-wrapper"


/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */
#line 1 "cgo-gcc-export-header-prolog"

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
typedef float _Complex GoComplex64;
typedef double _Complex GoComplex128;

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef _GoString_ GoString;
#endif
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif


// parse_access parses serialized access grant string.

extern AccessResult parse_access(char* p0);

// request_access_with_passphrase requests satellite for a new access grant using a passhprase.

extern AccessResult request_access_with_passphrase(char* p0, char* p1, char* p2);

// access_serialize serializes access grant into a string.

extern StringResult access_serialize(Access* p0);

// access_share creates new access grant with specific permission. Permission will be applied to prefixes when defined.

extern AccessResult access_share(Access* p0, Permission p1, SharePrefix* p2, GoInt p3);

// access_override_encryption_key overrides the root encryption key for the prefix in
// bucket with encryptionKey.
//
// This function is useful for overriding the encryption key in user-specific
// access grants when implementing multitenancy in a single app bucket.

extern Error* access_override_encryption_key(Access* p0, char* p1, char* p2, EncryptionKey* p3);

// free_string_result frees the resources associated with string result.

extern void free_string_result(StringResult p0);

// free_access_result frees the resources associated with access grant.

extern void free_access_result(AccessResult p0);

// stat_bucket returns information about a bucket.

extern BucketResult stat_bucket(Project* p0, char* p1);

// create_bucket creates a new bucket.
//
// When bucket already exists it returns a valid Bucket and ErrBucketExists.

extern BucketResult create_bucket(Project* p0, char* p1);

// ensure_bucket creates a new bucket and ignores the error when it already exists.
//
// When bucket already exists it returns a valid Bucket and ErrBucketExists.

extern BucketResult ensure_bucket(Project* p0, char* p1);

// delete_bucket deletes a bucket.
//
// When bucket is not empty it returns ErrBucketNotEmpty.

extern BucketResult delete_bucket(Project* p0, char* p1);

// free_bucket_result frees memory associated with the BucketResult.

extern void free_bucket_result(BucketResult p0);

// free_bucket frees memory associated with the bucket.

extern void free_bucket(Bucket* p0);

// list_buckets lists buckets.

extern BucketIterator* list_buckets(Project* p0, ListBucketsOptions* p1);

// bucket_iterator_next prepares next Bucket for reading.
//
// It returns false if the end of the iteration is reached and there are no more buckets, or if there is an error.

extern _Bool bucket_iterator_next(BucketIterator* p0);

// bucket_iterator_err returns error, if one happened during iteration.

extern Error* bucket_iterator_err(BucketIterator* p0);

// bucket_iterator_item returns the current bucket in the iterator.

extern Bucket* bucket_iterator_item(BucketIterator* p0);

// free_bucket_iterator frees memory associated with the BucketIterator.

extern void free_bucket_iterator(BucketIterator* p0);

// config_request_access_with_passphrase requests satellite for a new access grant using a passhprase.

extern AccessResult config_request_access_with_passphrase(Config p0, char* p1, char* p2, char* p3);

// config_open_project opens project using access grant.

extern ProjectResult config_open_project(Config p0, Access* p1);

// prepare_custommetadata creates a temporary SharePrefixes-Array to be filled by append_custommetadata and used by upload_set_custom_metadata2

extern void prepare_custommetadata();

// append_custommetadata appends one CustomMetadata by providing the contents directly

extern void append_custommetadata(char* p0, char* p1);

// upload_set_custom_metadata2 sets the customMetadata on an upload

extern Error* upload_set_custom_metadata2(Upload* p0);

// prepare_get_custommetadata 

extern void prepare_get_custommetadata(Object* p0);

extern CustomMetadataEntry get_next_custommetadata();

// download_object starts  download to the specified key.

extern DownloadResult download_object(Project* p0, char* p1, char* p2, DownloadOptions* p3);

// download_read downloads from object's data stream into bytes up to length amount.
// It returns the number of bytes read (0 <= bytes_read <= length) and
// any error encountered that caused the read to stop early.

extern ReadResult download_read(Download* p0, void* p1, size_t p2);

// download_info returns information about the downloaded object.

extern ObjectResult download_info(Download* p0);

// free_read_result frees any resources associated with read result.

extern void free_read_result(ReadResult p0);

// close_download closes the download.

extern Error* close_download(Download* p0);

// free_download_result frees any associated resources.

extern void free_download_result(DownloadResult p0);

// derive_encryption_key derives a salted encryption key for passphrase using the
// salt.
//
// This function is useful for deriving a salted encryption key for users when
// implementing multitenancy in a single app bucket.

extern EncryptionKeyResult derive_encryption_key(char* p0, void* p1, size_t p2);

// free_encryption_key_result frees the resources associated with encryption key.

extern void free_encryption_key_result(EncryptionKeyResult p0);

// free_error frees error data.

extern void free_error(Error* p0);

// internal_UniverseIsEmpty returns true if nothing is stored in the global map.

extern GoUint8 internal_UniverseIsEmpty();

// stat_object returns information about an object at the specific key.

extern ObjectResult stat_object(Project* p0, char* p1, char* p2);

// delete_object deletes an object.

extern ObjectResult delete_object(Project* p0, char* p1, char* p2);

// free_object_result frees memory associated with the ObjectResult.

extern void free_object_result(ObjectResult p0);

// free_object frees memory associated with the Object.

extern void free_object(Object* p0);

// list_objects lists objects.

extern ObjectIterator* list_objects(Project* p0, char* p1, ListObjectsOptions* p2);

// object_iterator_next prepares next Object for reading.
//
// It returns false if the end of the iteration is reached and there are no more objects, or if there is an error.

extern _Bool object_iterator_next(ObjectIterator* p0);

// object_iterator_err returns error, if one happened during iteration.

extern Error* object_iterator_err(ObjectIterator* p0);

// object_iterator_item returns the current object in the iterator.

extern Object* object_iterator_item(ObjectIterator* p0);

// free_object_iterator frees memory associated with the ObjectIterator.

extern void free_object_iterator(ObjectIterator* p0);

// open_project opens project using access grant.

extern ProjectResult open_project(Access* p0);

// close_project closes the project.

extern Error* close_project(Project* p0);

// free_project_result frees any associated resources.

extern void free_project_result(ProjectResult p0);

// prepare_shareprefixes creates a temporary SharePrefixes-Array to be filled by append_shareprefix and used by access_share2

extern void prepare_shareprefixes(size_t p0);

// append_shareprefix appends one SharePrefix by providing the contents directly

extern void append_shareprefix(char* p0, char* p1);

// access_share2 restricts a given scope with the provided caveat and the temporary encryption shareprefixes

extern AccessResult access_share2(Access* p0, Permission p1);

// upload_object starts an upload to the specified key.

extern UploadResult upload_object(Project* p0, char* p1, char* p2, UploadOptions* p3);

// upload_write uploads len(p) bytes from p to the object's data stream.
// It returns the number of bytes written from p (0 <= n <= len(p)) and
// any error encountered that caused the write to stop early.

extern WriteResult upload_write(Upload* p0, void* p1, size_t p2);

// upload_commit commits the uploaded data.

extern Error* upload_commit(Upload* p0);

// upload_abort aborts an upload.

extern Error* upload_abort(Upload* p0);

// upload_info returns the last information about the uploaded object.

extern ObjectResult upload_info(Upload* p0);

// upload_set_custom_metadata returns the last information about the uploaded object.

extern Error* upload_set_custom_metadata(Upload* p0, CustomMetadata p1);

// free_write_result frees any resources associated with write result.

extern void free_write_result(WriteResult p0);

// free_upload_result closes the upload and frees any associated resources.

extern void free_upload_result(UploadResult p0);

#ifdef __cplusplus
}
#endif
