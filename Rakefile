namespace :book do
  desc 'prepare build'
  task :prebuild do
    Dir.mkdir 'images' unless Dir.exists? 'images'
    Dir.glob("book/*/images/*").each do |image|
      FileUtils.copy(image, "images/" + File.basename(image))
    end
    Dir.glob("book/images/*").each do |image|
      FileUtils.copy(image, "images/" + File.basename(image))
    end
  end

  desc 'build basic book formats'
  task :sample => :prebuild do
    puts "Converting sample"
    `bundle exec asciidoctor-pdf -a pdf-stylesdir=pdf -a pdf-style=basic -a pdf-fontsdir=theme/fonts -r asciidoctor-diagram sample.adoc 2>/dev/null`
    puts " -- PDF  output at sample.pdf"
  end

  desc 'build basic book formats'
  task :build => :prebuild do
     # puts "Converting to HTML..."
     # `bundle exec asciidoctor -r asciidoctor-diagram index.adoc`
     # puts " -- HTML output at index.html"

     # puts "Converting to EPub..."
     # `bundle exec asciidoctor-epub3 -r asciidoctor-diagram iot-with-esp8266.adoc`
     # puts " -- Epub output at iot-with-esp8266.epub"

     # puts "Converting to Mobi (kf8)..."
     # `bundle exec asciidoctor-epub3 -r asciidoctor-diagram -a ebook-format=kf8 iot-with-esp8266.adoc`
     # puts " -- Mobi output at iot-with-esp8266.mobi"

    puts "Converting to PDF... (this one takes a while)"
    `bundle exec asciidoctor-pdf -r asciidoctor-diagram -a pdf-stylesdir=theme/pdf -a pdf-style=basic -a pdf-fontsdir=fonts -r asciidoctor-diagram index.adoc 2>/dev/null`
    puts " -- PDF  output at index.pdf"
#    `bundle exec find . -name "diag-*" -type f -delete`
  end
  desc 'Clean the doc'
  task :clean do
      puts " Clean up"
      `bundle exec rm *.pdf *.mobi *.epub *.html`
  end
end

task :default => "book:build"
