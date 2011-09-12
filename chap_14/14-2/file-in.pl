#!/usr/bin/perl

use strict;
use warnings;

my $file = 'file1';
my $count = 0;

open my $fh, $file or die "Can't open file";

while (<$fh>) {
	chomp;
	print;
	++$count;
	print STDERR "DEBUG: saw line $_";

	if ($count > 500) {
		$xyz = 5;
	}

	exit;
}

